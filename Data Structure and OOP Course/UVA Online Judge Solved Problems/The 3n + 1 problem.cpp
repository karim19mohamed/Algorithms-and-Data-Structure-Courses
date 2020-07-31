#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector<ll> cycle(ll n) { // a>b
	vector<ll> cnt(n + 1, 1);
	for (ll i = 1; i < n + 1; ++i) {
		ll a = i;
		while (a != 1) {
			a = (a % 2) ? 3 * a + 1 : a / 2;
			++cnt[i];
			if (a < n + 1) {
				if (cnt[a] != 1) {
					cnt[i] += cnt[a] - 1;
					break;
				}
			}
		}
	}
	return cnt;
}

int main() {
	int a, b;
	vector<ll> v = cycle(1000000);
	while (cin >> a >> b) {
		ll ans = 0;
		int s = min(a, b), e = max(a, b);
		for (int i = s; i <= e; ++i) {
			ans = max(ans, v[i]);
		}
		printf("%d %d %lld\n", a, b, ans);
	}
	return 0;
}

