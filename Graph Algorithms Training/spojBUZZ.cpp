#include <bits/stdc++.h>
using namespace std;
const int N = 251, M = 251 * 250;
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
//	memset(compID, -1, ne * sizeof(compID[0]));
	isArtID++;
	isBrdgeID++;
	for (rootID = 0; rootID < n; ++rootID) {
		cntRootChildren = 0;
		if (!~dfsTime[rootID])
			biConCompDFS(rootID);
	}
}

const int N1 = 251, N2 = 251;
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
int supNode[N], supComp[N], req[N];
bool ok(int mx,int nc,int b){
	n=b;
	init();
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<nc;j++)
		{
			if(abs(req[i]-supComp[j])<=mx)
				addEdge(i, j);
		}
	}
	return maxMatch(nc)==nc;
}
int main() {
	//freopen("test.in", "rt", stdin);
	int t, tc = 1;
	scanf("%d", &t);
	while (t--) {
		int m, b;
		scanf("%d%d%d", &n, &m, &b);
		init();
		for (int i = 0; i < n; i++)
			scanf("%d", supNode + i);
		for (int i = 0; i < b; i++)
			scanf("%d", req + i);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			addBiEdge(--x, --y);
		}
		biConComp();

		vector<vector<int> > comps(ncomp);
		for (int i = 0; i < n; i++) {
			for (int k = head[i]; ~k; k = nxt[k]) {
				int id = compID[k];
				int j = to[k];
				comps[id].push_back(i);
				comps[id].push_back(j);
			}
		}
		vid++;
		for (int i = 0; i < (int) comps.size(); i++) {
			sort(comps[i].begin(), comps[i].end());
			comps[i].resize(
					unique(comps[i].begin(), comps[i].end())
							- comps[i].begin());
			if (comps[i].size() <= 2) {
				comps[i].swap(comps.back()), comps.pop_back();
				i--;
				continue;
			}
			supComp[i] = 0;
			for(int j=0,x;j<(int)comps[i].size() && (x=comps[i][j],1);j++)
				supComp[i] += supNode[x], vis[x] = vid;
		}
		for (int i = 0; i < n; i++)
			if (vis[i] != vid) {
				vector<int> v(1, i);
				supComp[comps.size()] = supNode[i];
				comps.push_back(v);
			}

		printf("Buzz Mission %d: %d ", tc++, comps.size());
		if ((int)comps.size() > b) {
			puts("No");
			continue;
		}
		int s=0,e=251*1000;
		while(s<e){
			int m=s+((e-s)>>1);
			if(ok(m,comps.size(),b))
				e=m;
			else
				s=m+1;
		}
		printf("%d\n",s);
	}
}
