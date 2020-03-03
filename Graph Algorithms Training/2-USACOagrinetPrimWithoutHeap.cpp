/*
 TASK: agrinet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = N * N;
int cost[N][N];
void init(int n) {
	memset(cost, 0x3f, sizeof cost);
}

int dist[N], vis[N], vid;
int n = 128;

int prim() {
	vid++;
	memset(dist, 0x3f, n * sizeof dist[0]);
	int src = 0;
	int sol = 0;
	dist[src] = 0;
	int nxt = src;
	do {
		int cur = nxt;
		vis[cur] = vid;
		nxt = -1;
		int best = 0x3f3f3f3f;
		for (int j = 0; j < n; j++) {
			int dj = cost[cur][j];
			if (dist[j] > dj)
				dist[j] = dj;
			if (vis[j] != vid && best > dist[j])
				best = dist[j], nxt = j;
		}
		if (nxt != -1)
			sol += best;
	} while (nxt != -1);
	return sol;
}

int main() {
	freopen("agrinet.in", "rt", stdin);
	freopen("agrinet.out", "wt", stdout);

	scanf("%d", &n);
	init(n);
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++) {

			scanf("%d", &cost[a][b]);
		}
	int sol = prim();
	printf("%d\n", sol);
	return 0;
}
