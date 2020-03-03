/*
 TASK: agrinet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = N * N;
int head[N], nxt[M], to[M], cost[M], ne;
void init(int n) {
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
int n = 128;

int prim() {
	memset(dist, 0x3f, n * sizeof dist[0]);
	int src=0;
	dist[src] = 0;
	priority_queue<pair<int, int> > q;
//	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	int sol=0;
	q.push( { 0, src });
	while (q.size()) {
		int d = -q.top().first;
		int i = q.top().second;
		q.pop();
		if (dist[i] != d)
			continue;
		sol+=d;
		for (int k = head[i]; ~k; k = nxt[k]) {
			int j = to[k];
			int dj =  cost[k];
			if (dist[j] > dj) {
				dist[j] = dj;
				q.push( { -dj, j });
			}
		}
	}
	return sol;
}

int main() {
	freopen("agrinet.in", "rt", stdin);
	freopen("agrinet.out", "wt", stdout);

	scanf("%d", &n);
	init(n);
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++) {
			int c;
			scanf("%d", &c);
			addEdge(a, b, c);
		}
	int sol = prim();
	printf("%d\n", sol);
	return 0;
}
