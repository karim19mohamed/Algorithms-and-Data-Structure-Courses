#include <bits/stdc++.h>
using namespace std;
const int N1 = 1000, N2 = 1000, M = N1 * N2;
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
int a[N1], b[N2];
int main() {
	freopen("test.in", "rt", stdin);
	int t, tc = 1;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d", &n);
		init();
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			scanf("%d", b + i);
			for (int j = 0; j < n; j++){
				if(a[j] )
				{
					long long  P=b[i];
					long long Q=a[j];
					long long K=P/Q;
					if(Q*K==P)
						addEdge(j, i);
				}else if(!b[i])
					addEdge(j, i);
			}
		}
		int rem=n+m-maxMatch(m);
		printf("Case %d: %d\n",tc++,m+n-rem);
	}
}
