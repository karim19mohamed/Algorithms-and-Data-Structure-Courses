/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 128, M = 10000 * 2;
int cost[N][N];
void init(int n) {
	memset(cost, 0x3f, sizeof cost);
}

int dist[N], notVis[N];
int n = 128;

void dij(int src) {
	memset(dist, 0x3f, n * sizeof dist[0]);
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
			int dj = dist[cur] + cost[cur][j];
			if (dist[j] > dj)
				dist[j] = dj;
			if (best > dist[j])
				best = dist[j], nxt = k;
		}
	} while (nxt != -1);
}

int main() {
	freopen("comehome.in", "rt", stdin);
	freopen("comehome.out", "wt", stdout);
	int m;
	scanf("%d", &m);
	init(n);
	while (m--) {
		char a, b;
		int c;
		scanf(" %c %c%d", &a, &b, &c);
		if (c < cost[a][b])
			cost[a][b] = cost[b][a] = c;
	}
	dij('Z');
	char sol = min_element(dist + 'A', dist + 'Z') - dist;
	printf("%c %d\n", sol, dist[sol]);
	return 0;
}
