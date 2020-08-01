#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool vis[30][30];
int solve(vector<int> v[30], int node) {
	int ans = 0;
	for (int i = 0; i < (int) v[node].size(); ++i) {
		if (!vis[node][v[node][i]]) {
			vis[node][v[node][i]] = vis[v[node][i]][node] = 1;
			ans = max(ans, 1 + solve(v, v[node][i]));
			vis[node][v[node][i]] = vis[v[node][i]][node] = 0;
		}
	}
	return ans;
}

int main() {
	int n, m, a, b;
	while (scanf("%d %d", &n, &m) == 2 && n + m) {
		vector<int> v[30];
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b), v[b].push_back(a);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, solve(v, i));
		printf("%d\n", ans);
	}
	return 0;
}

