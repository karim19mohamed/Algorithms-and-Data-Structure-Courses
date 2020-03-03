/*
 TASK: fence
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 501, M = 1024 * 2;
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
		k = nxt[k];
		tour(j);
	}
	res[rs++] = i;
}
bool degOdd[N];
int main() {
	freopen("fence.in", "rt", stdin);
	freopen("fence.out", "wt", stdout);
	int n = 501, m;
	scanf("%d", &m);
	init(n);
	vector<pair<int, int> > v;
	int mn = 501;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		//addBiEdge(--a, --b);
		degOdd[(--a)] ^= 1;
		degOdd[(--b)] ^= 1;
		mn = min(mn, a);
		mn = min(mn, b);
		v.emplace_back(min(a, b), max(a, b));
	}
	sort(v.rbegin(), v.rend());
	for (auto p : v) {
		addBiEdge(p.first, p.second);
		//	printf("%d %d\n",p.first,p.second);
	}
//	for (int i = 0; i < 7; i++) {
//		printf("%d: ", i);
//		for (int k = head[i]; ~k; k = nxt[k]) {
//			int j = to[k];
//			printf("%d%c", j, " \n"[nxt[k] == -1]);
//		}
//	}
	int c = count(degOdd, degOdd + 501, 1);
	if (c == 0) {
		tour(mn);
	} else if (c == 2) {
		int id = find(degOdd, degOdd + 501, 1) - degOdd;
		tour(id);
	} else {

	}
	while (rs--)
		printf("%d\n", res[rs] + 1);
	return 0;
}
