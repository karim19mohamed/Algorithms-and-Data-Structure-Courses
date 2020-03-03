/*
 TASK: fence
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 7, M = 200;
int head[N], nxt[M], to[M], ne;
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
bool vis[M];

int res[M], rs = 0;

void tour(int i) {
	for (int &k = head[i]; ~k; ) {
		if (vis[k])
		{
			k = nxt[k];
			continue;
		}
		vis[k ^ 1] = 1;
		int j = to[k];
		int id=k;
		k = nxt[k];
		tour(j);
		res[rs++]=id;
	}
}
bool degOdd[N];
int main() {
	int n = 7, m;
	scanf("%d", &m);
	init(n);

	int mn = 7;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);

		degOdd[(a)] ^= 1;
		degOdd[(b)] ^= 1;
		mn = min(mn, a);
		mn = min(mn, b);
		addBiEdge(a,b);
	}
	int c = count(degOdd, degOdd + 7, 1);
	if (c == 0) {
		tour(mn);
	} else if (c == 2) {
		int id = find(degOdd, degOdd + 7, 1) - degOdd;
		tour(id);
	} else {
		printf("No solution\n");
	}
	if(rs!=ne/2)
		printf("No solution\n");
	while (rs--)
		printf("%d %c\n", 1+res[rs] /2,"+-"[res[rs]&1]);
	return 0;
}
