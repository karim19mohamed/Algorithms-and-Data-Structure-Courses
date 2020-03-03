/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 201, M = N * N;
const int N2 = 1 << (int) ceil(log(N) / log(2)), N2M1 = N2 - 1;
int vis[N], vid;
struct graph {
	int head[N], nxt[M], to[M], cost[M], ne, n;
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

	int q[N2], qsz, frnt, bk;
	int inQ[N], inqid;

	bool bellman(int src) {
		memset(dist, 0x3f, n * sizeof dist[0]);
		dist[src] = 0;
		qsz = bk = frnt = 0;
		inqid++;
		q[bk] = src, qsz++, bk = ++bk & N2M1, inQ[src] = inqid;
		int nn = n;
		while (qsz && nn--) {
			int s = qsz;
			while (s--) {
				int f;
				f = q[frnt], qsz--, frnt = ++frnt & N2M1, inQ[f] = 0;
				for (int k = head[f]; ~k; k = nxt[k]) {
					int t = to[k], c = cost[k];
					int d = dist[f] + c;
					if (dist[t] > d && d < 0) {
						dist[t] = d;
						if (!nn && vis[t] == vid)
							return false;
						if (inQ[t] != inqid)
							q[bk] = t, qsz++, bk = ++bk & N2M1, inQ[t] = inqid;
					}
				}
			}
		}
		return true;
	}
	void dfs(int cur) {
		if (vis[cur] == vid)
			return;
		vis[cur] = vid;
		for (int i = head[cur]; ~i; i = nxt[i])
			dfs(to[i]);
	}
};
int cost[N];
int main() {
	//freopen("comehome.in", "rt", stdin);
	//freopen("comehome.out", "wt", stdout);
	int n;
	while (scanf("%d", &n), ~n) {
		n ++;
		graph g, r;
		g.init(n);
		r.init(n);
		for (int i = 0; i < n -1; i++) {
			scanf("%d", &cost[i]);
			int m;
			scanf("%d", &m);
			while (m--) {
				int t;
				scanf("%d", &t);
				t--;
				g.addEdge(i, t, 0);
				r.addEdge(t, i, 0);
			}
		}
		for(int i=0;i<n;i++)
			for(int k=g.head[i];~k;k=g.nxt[k])
				g.cost[k]=-cost[g.to[k]];

		int src = n - 1;
		g.addEdge(src, 0, -100);
		r.addEdge(0, src, -100);
		int snk=src-1;
		vid++;
		r.dfs(snk);
		if(!g.bellman(src) || g.dist[snk]<0)
			printf("winnable\n");
		else
			printf("hopeless\n");
	}
	return 0;
}
