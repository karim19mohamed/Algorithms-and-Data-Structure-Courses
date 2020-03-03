/*
 TASK: schlnet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 120, M = 200 << 3;
int head[N], nxt[M], to[M], ne, n;
void init() {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}

int dfsTime[N], low[N], nxtTime, stk[N], stkSz, ncomp, compID[N];
void sccDFS(int i) {
	dfsTime[i] = low[i] = nxtTime++;
	stk[stkSz++] = i;
	for (int k = head[i]; ~k; k = nxt[k]) {
		int j = to[k];
		if (dfsTime[j] == -1) {
			sccDFS(j);
			low[i] = min(low[i], low[j]);
		} else if (compID[j] == -1) {
			low[i] = min(low[i], low[j]);
		}
	}
	if (low[i] == dfsTime[i]) {
		do {
			compID[stk[--stkSz]] = ncomp;
		} while (stk[stkSz] != i);
		ncomp++;
	}
}
void scc() {
	memset(dfsTime, -1, n * sizeof dfsTime[0]);
	memset(compID, -1, n * sizeof compID[0]);
	nxtTime = ncomp = 0;
	for (int i = 0; i < n; ++i)
		if (!~dfsTime[i]) //==-1
			sccDFS(i);
}

#define VAR(ID) ((ID)<<1)
#define NOTVAR(ID) (VAR(ID)|1)
#define NOT(ID) ((ID)^1)

void addOr(int v1, int v2) {
	addEdge(NOT(v1), v2);
	addEdge(NOT(v2), v1);
}

void addXor(int v1, int v2) {
	addOr(v1, v2);
	addOr(NOT(v1), NOT(v2));
}

void addImplication(int v1, int v2) {
	addOr(NOT(v1), v2);
}

int vis[N], vid;
int res[N];
void dfs(int i) {
	if (vis[i] == vid)
		return;
	vis[i] = vid;
	for (int k = head[i]; ~k; k = nxt[k]) {
		dfs(to[k]);
	}
	if (res[compID[i]] == -1) {
		res[compID[i]] = 1;
		res[compID[NOT(i)]] = 0;
	}
}

bool getSolution() {
	for (int i = 0; i < (n >> 1); i++) {
		if (compID[VAR(i)] == compID[NOTVAR(i)])
			return false;
	}
	vid++;
	memset(res, -1, n * sizeof res[0]);
	for (int i = 0; i < n; i++)
		if (vis[i] != vid)
			dfs(i);
	return true;
}

int s, a;
#define S(ID) (ID)
#define A(ID) ((ID)+s)

int main() {
	freopen("test.in", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d%d%d", &s, &a, &m);
		n = (s + a) << 1;
		init();
		while (m--) {
			int s1, a1, s2, a2;
			scanf("%d%d%d%d", &s1, &a1, &s2, &a2);
			bool down = (s2 - s1) > 0;
			bool right = (a2 - a1) > 0;
			if (s1 == s2) {
				int id = S(s1);
				id = right ? VAR(id) : NOTVAR(id);
				addOr(id, id);
			} else if (a1 == a2) {
				int id = A(a1);
				id = down ? VAR(id) : NOTVAR(id);
				addOr(id, id);
			}else{
				int a=S(s1),b=A(a2);
				int c=S(s2),d=A(a1);
				a=right?VAR(a):NOTVAR(a);
				c=right?VAR(c):NOTVAR(c);
				b=down?VAR(b):NOTVAR(b);
				d=down?VAR(d):NOTVAR(d);
				addOr(a, c);
				addOr(a, d);
				addOr(b, c);
				addOr(b, d);
			}
		}
		scc();
		puts(getSolution()?"Yes":"No");
	}
}
