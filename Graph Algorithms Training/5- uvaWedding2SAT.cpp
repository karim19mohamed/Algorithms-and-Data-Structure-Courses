/*
 TASK: schlnet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 120, M = 30 * 4 + 60 * 59 + 2;
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
	if (res[compID[i]] == -1) {// == -1 => it is SNK 34an ana lesa 5areg mn el recursion fa akid ana SNK
		res[compID[i]] = 1; // 1 => hay3odo na7yat el 3arosa
		res[compID[NOT(i)]] = 0; // 0 => hay3odo na7yt el 3ariis
	}
}

bool getSolution() {
	for (int i = 0; i < (n >> 1); i++) {
		if (compID[VAR(i)] == compID[NOTVAR(i)])
			// lw ana w el not bta3y fi nafs el comp.
			return false;
	}
	vid++;
	memset(res, -1, n * sizeof res[0]);//b3tbrha kolha SNK fil awel
	for (int i = 0; i < n; i++)
		if (vis[i] != vid)
			dfs(i);
	return true;
}



#define H(ID) ((ID)<<1) // badrb el ID * 2 fa barg3 el even ely hwa el H
#define W(ID) (H(ID)|1) // bazawed 3ala ID el H 1 fa bygbly ely gambo ely hya el W

int getID(char a[4]) {
	int cid;
	char type;
	sscanf(a, "%d%c", &cid, &type);
	return VAR(type=='h'?H(cid):W(cid));
}

int main() {
	freopen("test.in", "rt", stdin);
	int c, r;
	while (scanf("%d%d", &c, &r), c || r) {
		n = c << 2; //H & W
		init();
		addOr(VAR(W(0)), VAR(W(0))); // b3mlha OR m3 nafssaha fa damn enha hatro7 ll true
		for (int i = 0; i < c; i++)
			addXor(VAR(H(i)), VAR(W(i))); // bygarab y7otny fi saf el 3arosa mara w fi saf el 3arees mara
		while (r--) {
			char a[4], b[4];
			scanf("%s%s", a, b);
			addOr(getID(a), getID(b));
		}
		scc();// bn2asem el graph strongly connected comp.
		if (getSolution())
			for (int i = 1; i < c; i++)
				printf("%d%c%c", i, res[compID[VAR(H(i))]] ? 'h' : 'w',
						" \n"[i == c - 1]);// e7na bngyb el node bta3t el H lw true yb2a print h w m3nah eno fi na7yt el 3arossa  lw la2 print w
		else
			puts("bad luck");

	}
}
