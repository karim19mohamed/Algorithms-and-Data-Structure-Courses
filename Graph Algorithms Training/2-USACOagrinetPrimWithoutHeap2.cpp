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

int dist[N], notVis[N];
int n = 128;

int prim(){
	memset(dist, 0x3f, n * sizeof dist[0]);
	int src = 0;
	int sol = 0;
	dist[src] = 0;
	int nxt = src;
	for (int i = 0; i < n; i++)
		notVis[i] = i;
	int notVisSz = n;

	do {
		int cur = notVis[nxt];
		notVis[nxt] = notVis[--notVisSz];
		nxt = -1;
		int best = 0x3f3f3f3f;
		for (int k = 0; k < notVisSz; k++) {
			int j = notVis[k];
			int dj =  cost[cur][j];
			if (dist[j] > dj)
				dist[j] = dj;
			if (best > dist[j])
				best = dist[j], nxt = k;
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
