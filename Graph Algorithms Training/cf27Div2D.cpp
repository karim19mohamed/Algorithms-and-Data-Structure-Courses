#include <bits/stdc++.h>
using namespace std;
const int N = 200, M = 100*99*4;
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

#define VAR(ID) ((ID)<<1) // return node ID
#define NOTVAR(ID) (VAR(ID)|1) // return Not node ID
#define NOT(ID) ((ID)^1) // 3andi even w 3awz el odd aw el 3akss

void addOr(int v1, int v2) {
	// a|b == ~a => b && ~b => a
	addEdge(NOT(v1), v2);
	addEdge(NOT(v2), v1);
}

void addXor(int v1, int v2) {
	// a^b == a|b && ~a | ~b
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
	if (res[compID[i]] == -1) { // == -1 => it is SNK 34an ana lesa 5areg mn el recursion fa akid ana SNK
		res[compID[i]] = 1; // 1 => hay3odo na7yat el 3arosa
		res[compID[NOT(i)]] = 0; // 0 => hay3odo na7yt el 3ariis
	}
}

bool getSolution() {
	scc();
	for (int i = 0; i < (n >> 1); i++) {
		if (compID[VAR(i)] == compID[NOTVAR(i)])
			// lw ana w el not bta3y fi nafs el comp.
			return false;
	}
	vid++;
	memset(res, -1, n * sizeof res[0]); //b3tbrha kolha SNK fil awel
	for (int i = 0; i < n; i++)
		if (vis[i] != vid)
			dfs(i);
	return true;
}

int a[100], b[100];

int main() {
	freopen("test.in", "rt", stdin);
	int c, r;
	while (~scanf("%d%d", &c, &r)) {
		n = r << 1;
		init();
		for (int i = 0; i < r; i++) {
			scanf("%d%d", &a[i], &b[i]);
			if (a[i] > b[i])
				swap(a[i], b[i]);
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i] && a[j] < b[i]
						&& (b[j] < a[i] || b[j] > b[i])) {
					addXor(VAR(i), VAR(j));
				}
				if (b[j] > a[i] && b[j] < b[i]
						&& (a[j] < a[i] || a[j] > b[i])) {
					addXor(VAR(i), VAR(j));
				}
			}
		}
		if(getSolution())
		{
			for(int i=0;i<n;i+=2)
				printf("%c","io"[res[compID[i]]]);
			puts("");
		}
		else
			puts("Impossible");
	}
}
