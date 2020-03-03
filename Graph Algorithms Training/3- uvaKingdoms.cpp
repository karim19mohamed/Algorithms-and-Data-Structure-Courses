/*
 TASK: agrinet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 16, M = N * N;
int cost[N][N];
void init(int n) {
	memset(cost, 0x3f, sizeof cost);
}

int dist[N], notVis[N];
int n ;

int prim(int i) {
	memset(dist, 0x3f, n * sizeof dist[0]);
	int src = 0;
	int sol = 0;
	dist[src] = 0;
	int nxt = src;

	int notVisSz = 0;
	for (int j = 0; j < n; j++)
		if ((i >> j) & 1)
			notVis[notVisSz++] = j;

	do {
		int cur = notVis[nxt];
		notVis[nxt] = notVis[--notVisSz];
		nxt = -1;
		int best = 0x3f3f3f3f;
		for (int k = 0; k < notVisSz; k++) {
			int j = notVis[k];
			int dj = cost[cur][j];
			if (dist[j] > dj)
				dist[j] = dj;
			if (best > dist[j])
				best = dist[j], nxt = k;
		}
		if (nxt != -1)
			sol += best;
	} while (nxt != -1);
	if(notVisSz) return 1e9;
	return sol;
}
int pop[16];

int p=0;
int res;
int main() {
	//freopen("agrinet.in", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, K;
		scanf("%d%d%d", &n, &m, &K);
		init(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", pop + i);

		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (cost[--a][--b] > c)
				cost[a][b] = cost[b][a] = c;
		}
		int res = 0;
		for (int i = (1<<n)-1; i>0; i -= 2) {
			int p = 0;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)
					p += pop[j];
			if(p<=res)continue;
			int sol = prim(i);
			if (sol <= K)
				res = max(res, p);
		}
		printf("%d\n", res);
	}

	return 0;
}
