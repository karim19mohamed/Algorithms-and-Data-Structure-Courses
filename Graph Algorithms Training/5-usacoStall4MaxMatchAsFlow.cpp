/*
 TASK: stall4
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 402, M = (200*200+200+200)<<1;
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
			cap[k] -= f;
			cap[k ^ 1] += f;
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

#define B(ID) (ID)
#define H(ID) ((ID)+b)

int main() {
	freopen("stall4.in", "rt", stdin);
	freopen("stall4.out", "wt", stdout);
	int b, h;
	scanf("%d%d", &b, &h);
	n = b + h + 2;
	init();
	src = n - 2, snk = n - 1;
	for (int i = 0; i < b; i++) {
		addAugEdge(src, B(i), 1);
		int x;
		scanf("%d", &x);
		while (x--) {
			int hid;
			scanf("%d", &hid);
			addAugEdge(B(i), H(--hid), 1);
		}
	}
	for (int i = 0; i < h; i++)
		addAugEdge(H(i), snk, 1);
	printf("%d\n", maxFlow());
}
