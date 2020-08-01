#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n, m;
string s[109], rule;
void solve(string ans, int idx) {
	if (idx == rule.size()) {
		cout << ans << endl;
		return;
	}
	if (rule[idx] == '#') {
		for (int i = 0; i < n; ++i) {
			solve(ans + s[i], idx + 1);
		}
	} else {
		string c = "0";
		for (int i = 0; i < 10; ++i) {
			solve(ans + c, idx + 1);
			c[0] = c[0] + 1;
		}
	}
}

int main() {
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			cin >> rule;
		}
		puts("--");
		solve("", 0);
	}
	return 0;
}

