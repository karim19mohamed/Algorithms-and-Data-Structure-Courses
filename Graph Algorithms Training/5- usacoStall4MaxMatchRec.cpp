/*
 TASK: stall4
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N1 = 200,N2 = 200, M = N1 * N2;
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
int lf[N1],rt[N2],vis[N1],vid;
bool canMatch(int lid){
	if(vis[lid]==vid)
		return 0;
	vis[lid]=vid;
	for(int k=head[lid];~k;k=nxt[k]){
		int rid=to[k];
		if(rt[rid]==-1 || canMatch(rt[rid])){
			lf[lid]=rid;
			rt[rid]=lid;
			return 1;
		}
	}
	return 0;
}
int maxMatch(int n2){
	memset(rt, -1, n2 * sizeof(rt[0]));
	int res=0;
	for(int i=0;i<n;i++)
		if(++vid,canMatch(i))
			res++;
		else
			lf[i]=-1;
	return res;
}
int main() {
	freopen("stall4.in", "rt", stdin);
	freopen("stall4.out", "wt", stdout);
	int b, h;
	scanf("%d%d", &b, &h);
	n = b;
	init();
	for (int i = 0; i < b; i++) {
		int x;
		scanf("%d", &x);
		while (x--) {
			int hid;
			scanf("%d", &hid);
			addEdge(i, --hid);
		}
	}
	printf("%d\n", maxMatch(h));
}
