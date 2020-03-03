/*
 TASK: ditch
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 200, M = 400;
int head[N], nxt[M], to[M], cap[M], ne, n;
void init() {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t, int c) {
	nxt[ne] = head[f];
	to[ne] = t;
	cap[ne] = c;
	head[f] = ne++;
}
void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}
int src, snk, vid, vis[N];

int dfs(int i, int FLOW) {
	if (i == snk)
		return FLOW;
	if (!FLOW)
		return 0;
	if (vis[i] == vid)
		return 0;
	vis[i] = vid;
	for (int k = head[i]; ~k; k = nxt[k]) {
		int j = to[k], c = cap[k];
		int f = dfs(j, min(FLOW, c));
		if (f) {
			cap[k]-=f;
			cap[k^1]+=f;
			return f;
		}
	}
	return 0;
}
int maxFlow() {
	if (src == snk)
		return 1e9;
	int flow = 0, f;
	while (vid++, (f = dfs(src, 1e9)))
		flow += f;
	return flow;
}

int main() {
	freopen("ditch.in", "rt", stdin);
	freopen("ditch.out", "wt", stdout);
	int m;
	scanf("%d%d", &m, &n);
	init();
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addAugEdge(--a, --b, c);
	}
	src = 0, snk = n - 1;
	printf("%d\n", maxFlow());
}
