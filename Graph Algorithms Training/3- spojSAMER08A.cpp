/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 500, M = 10000;
struct graph {
	int head[N], nxt[M], to[M], cost[M], ne;
	int n;
	void init(int n) {
		this->n = n;
		memset(head, -1, n * sizeof(head[0]));
		ne = 0;
	}
	void addEdge(int f, int t, int c) {
		nxt[ne] = head[f];
		to[ne] = t;
		cost[ne] = c;
		head[f] = ne++;
	}

	int dist[N];

	void dij(int src) {
		memset(dist, 0x3f, n * sizeof dist[0]);
		dist[src] = 0;
		priority_queue<pair<int, int> > q;
//	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

		q.push( { 0, src });
		while (q.size()) {
			int d = -q.top().first;
			int i = q.top().second;
			q.pop();
			if (dist[i] != d)
				continue;
			for (int k = head[i]; ~k; k = nxt[k]) {
				int j = to[k];
				int dj = d + cost[k];
				if (dist[j] > dj) {
					dist[j] = dj;
					q.push( { -dj, j });
				}
			}
		}
	}
} g, r, s;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m), n || m) {
		g.init(n);
		r.init(n);
		s.init(n);
		int src, snk;
		scanf("%d%d", &src, &snk);
		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			g.addEdge(a, b, c);
			r.addEdge(b, a, c);
		}
		g.dij(src);
		r.dij(snk);
		for(int i=0;i<n;i++)
			for(int k=g.head[i];~k;k=g.nxt[k])
			{
				int j=g.to[k],c=g.cost[k];
				if(c+g.dist[i]+r.dist[j]>g.dist[snk])
					s.addEdge(i, j, c);
			}
		s.dij(src);
		printf("%d\n",s.dist[snk]>1e9?-1:s.dist[snk]);
	}
	return 0;
}
