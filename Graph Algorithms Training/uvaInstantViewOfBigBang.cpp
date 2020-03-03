/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1001, M = 3000;
int head[N], nxt[M], to[M], cost[M], ne;
inline void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
inline void addEdge(int f, int t, int c) {
	nxt[ne] = head[f];
	to[ne] = t;

	cost[ne] = c;
	head[f] = ne++;
}

int dist[N];
int n;

const int N2 = 1 << (int) ceil(log(N) / log(2)), N2M1 = N2 - 1;
int q[N2], qsz, frnt, bk;
int inQ[N], inqid;
int vis[N], vid;
inline int bellman() {
	memset(dist, 0, n * sizeof dist[0]);
	qsz = bk = frnt = 0;
	inqid++;
	for(int src=0;src<n;src++)
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
				if (dist[t] > d) {
					dist[t] = d;

					if (!nn)
						vis[t]=vid;
					if (inQ[t] != inqid)
						q[bk] = t, qsz++, bk = ++bk & N2M1, inQ[t] = inqid;
				}
			}
		}
	}
	return -1;
}

inline void dfs(int cur) {
	if (vis[cur] == vid)
		return;
	vis[cur] = vid;
	for (int i = head[cur]; ~i; i = nxt[i])
		dfs(to[i]);
}
int main() {
	int tt, tc = 0;
	scanf("%d", &tt);
	while (tt--) {
		int m;
		scanf("%d%d", &n, &m);
		//int src = n++;
		init(n);
		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			addEdge(b, a, c);
		}

		vid++;
		bellman();
		vid++;
		bool ok=0;
		for (int i = 0; i < n ; ++i)
			if (vis[i] == vid-1)
				dfs(i),ok=1;
		printf("Case %d:", ++tc);
		for (int i = 0; i < n; ++i)
			if (vis[i] == vid)
				printf(" %d", i);
		if (!ok)
			printf(" impossible");
		puts("");
	}
	return 0;
}
