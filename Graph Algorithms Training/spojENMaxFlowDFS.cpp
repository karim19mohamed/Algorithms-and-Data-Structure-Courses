#include <bits/stdc++.h>
using namespace std;
const int N = 30011<<1, M = (119407<<1)+N;
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
	while (++vid, (f = dfs(src, 1e9)))
		flow += f;
	return flow;
}
#define IN(id) ((id)<<1)
#define OUT(id) (IN(id)+1)

int main() {
	//freopen("test.in", "rt", stdin);
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		assert(m<=119407);
		::n = n << 1;
		init();
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--,b--;
			addAugEdge(OUT(a), IN(b), 1e9);
		}
		for (int i = 0; i < n; i++)
			addAugEdge(IN(i), OUT(i), 1);
		src = OUT(0), snk = OUT(n - 1);
		assert(maxFlow()==1);
		for (int i = 0; i < n; i++)
			if(vis[IN(i)]==vid && vis[OUT(i)]!=vid )
			{
				printf("%d\n",i+1);
				break;
			}
	}
}
