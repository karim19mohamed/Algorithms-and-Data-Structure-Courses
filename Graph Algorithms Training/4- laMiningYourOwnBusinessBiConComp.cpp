/*
 TASK: schlnet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 1, M = 2 * 5e4;
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
void addBiEdge(int a, int b) {
	addEdge(a, b);
	addEdge(b, a);
}

int dfsTime[N], low[N], nxtTime, stk[M], stkSz, ncomp, compID[M];
int isArt[N], isArtID, isBridge[M], isBrdgeID, rootID, cntRootChildren;

void extractComp(int k) {
	do {
		int e = stk[--stkSz];
		compID[e] = compID[e ^ 1] = ncomp;
	} while (stk[stkSz] != k);
	ncomp++;
}

void biConCompDFS(int i, int pe = -1) {
	dfsTime[i] = low[i] = nxtTime++;
	for (int k = head[i]; ~k; k = nxt[k]) {
		if ((k ^ 1) == pe)
			continue;
		int j = to[k];
		if (dfsTime[j] == -1) {
			stk[stkSz++] = k;
			biConCompDFS(j, k);
			low[i] = min(low[i], low[j]);
			if (i == rootID) {
				if (++cntRootChildren > 1)
					isArt[i] = isArtID;
				extractComp(k);
			} else if (low[j] >= dfsTime[i]) {
				isArt[i] = isArtID;
				extractComp(k);
			}
			if (low[j] > dfsTime[i])
				isBridge[k] = isBridge[k ^ 1] = isBrdgeID;
		} else {
			if (dfsTime[j] < dfsTime[i])
				stk[stkSz++] = k;
			low[i] = min(low[i], dfsTime[j]);
		}
	}
}

void biConComp() {
	nxtTime = 0;
	ncomp = 0;
	memset(dfsTime, -1, n * sizeof(dfsTime[0]));
	isArtID++;
	isBrdgeID++;
	for (rootID = 0; rootID < n; ++rootID) {
		cntRootChildren = 0;
		if (!~dfsTime[rootID])
			biConCompDFS(rootID);
	}
}

int main() {
	//	freopen("test.in", "rt", stdin);
//	freopen("schlnet.out", "wt", stdout);
	int m, tc = 0;
	while (++tc, scanf("%d", &m), m) {
		init(N);
		n = 0;
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			n = max(n, max(a, b));
			addBiEdge(--a, --b);
		}
		biConComp();
		cout << "Case " << tc << ": ";
		if (ncomp == 1) {
			cout << "2 " << (((n - 1ll) * n) >> 1) << endl;
			continue;
		}
		vector<set<int> > cmpArt(ncomp), cmpNotArt(ncomp);
		for (int i = 0; i < n; i++)
			for (int k = head[i]; ~k; k = nxt[k]) {
				int j = to[k];
				int a[] = { i, j };
				for (int b = 0; b < 2; b++) {
					int cur = a[b];
					(isArt[cur] == isArtID ? cmpArt : cmpNotArt)[compID[k]].insert(cur);
				}
			}
		long long res = 1, cnt = 0;
		for (int i = 0; i < ncomp; i++)
			if (cmpArt[i].size() == 1)
				res *= cmpNotArt[i].size(), cnt++;
		cout << cnt << " " << res << endl;
	}
	return 0;
}
