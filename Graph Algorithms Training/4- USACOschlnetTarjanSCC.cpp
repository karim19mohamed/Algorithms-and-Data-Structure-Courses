
/*
 TASK: schlnet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = N * N;
int head[N], nxt[M], to[M], ne, n;
void init(int n) {
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
		if (!~dfsTime[i])//==-1
			sccDFS(i);
}

int main() {
	freopen("schlnet.in", "rt", stdin);
	freopen("schlnet.out", "wt", stdout);
	scanf("%d", &n);
	init(n);
	for (int i = 0; i < n; i++) {
		int x;
		while (scanf("%d", &x), x) {
			addEdge(i, --x);
		}
	}
	scc();
	bool notSrc[N] = { 0 }, notSnk[N] = { 0 };
	for (int i = 0; i < n; i++)
		for (int k = head[i]; ~k; k = nxt[k]) {
			int j = to[k];
			if (compID[i] != compID[j]) {
				notSrc[compID[j]] = 1;
				notSnk[compID[i]] = 1;
			}
		}
	int nsrc = count(notSrc, notSrc + ncomp, 0);
	int nsnk = count(notSnk, notSnk + ncomp, 0);
	cout<<nsrc<<endl;
	cout<<(ncomp==1?0:max(nsnk,nsrc))<<endl;
	return 0;
}
