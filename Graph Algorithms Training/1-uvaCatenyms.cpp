#include <bits/stdc++.h>
using namespace std;
const int N = 128, M = 1000;
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

int res[M], rs = 0;

void tour(int i) {
	for (int &k = head[i]; ~k;) {
		int j = to[k];
		int id = k;
		k = nxt[k];
		tour(j);
		res[rs++] = id;
	}
}
int deg[N];
int main() {
//	freopen("fence.in", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n = 128, m;
		scanf("%d", &m);
		init(n);
		memset(deg, 0, sizeof deg);
		rs = 0;
		vector<string> v;
		int mn = 'z' + 1;
		while (m--) {
			char str[21];
			scanf("%s", str);
			int a = str[0], b = str[strlen(str) - 1];
			deg[a]++;
			deg[b]--;
			mn = min(mn, a);
			mn = min(mn, b);
			v.emplace_back(str);
		}
		sort(v.rbegin(), v.rend());
		for (auto p : v)
			addEdge(p[0], *p.rbegin());

		int one = 0, neg = 0, s;
		bool noSol = 0;
		for (int i = 'a'; i <= 'z'; i++)
			switch (deg[i]) {
			case 0:
				break;
			case 1:
				one++, s = i;
				break;
			case -1:
				neg++;
				break;
			default:
				noSol = 1;
			}

		if (one > 1 || neg > 1)
			noSol = 1;
		if (one)
			tour(s);
		else
			tour(mn);
		if (rs != ne)
			noSol = 1;
		if (noSol)
			printf("***\n");
		else
			while (rs--)
				printf("%s%c", v[res[rs]].c_str(), ".\n"[!rs]);

	}
	return 0;
}
