/*
 TASK: stall4
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N1 = 120, N2 = 120, M = N1 * N2;
int head[N1], nxt[M], to[M], ne, n;
void init() {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
int lf[N1], rt[N2], vis[N1], vid;
bool canMatch(int lid) {
	if (vis[lid] == vid)
		return 0;
	vis[lid] = vid;
	for (int k = head[lid]; ~k; k = nxt[k]) {
		int rid = to[k];
		if (rt[rid] == -1 || canMatch(rt[rid])) {
			lf[lid] = rid;
			rt[rid] = lid;
			return 1;
		}
	}
	return 0;
}
int maxMatch(int n2) {
	memset(rt, -1, n2 * sizeof(rt[0]));
	int res = 0;
	for (int i = 0; i < n; i++)
		if (++vid, canMatch(i))
			res++;
		else
			lf[i] = -1;
	return res;
}

int visL[N1], visR[N2];
void dfs(int lid) {
	if (visL[lid] == vid)
		return;
	visL[lid] = vid;
	for (int k = head[lid]; ~k; k = nxt[k]) {
		int rid=to[k];
		visR[rid]=vid;
		dfs(rt[rid]);
	}
}
int main() {
	freopen("test.in", "rt", stdin);
	int t = 1, m;
	scanf("%d", &t);
	while (t--) {
		n = 120;
		init();
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			addEdge(x, y);
		}
		printf("%d\n", maxMatch(n));
		/*vid++;
		for (int i = 0; i < n; i++)
			if (lf[i] == -1)
				dfs(i);
		for (int i = 0; i < n; i++){
			if(visL[i]!=vid)
				printf("r %d\n",i);
			if(visR[i]==vid)
				printf("c %d\n",i);
		}*/
	}
}
