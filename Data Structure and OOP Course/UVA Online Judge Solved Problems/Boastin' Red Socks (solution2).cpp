#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 50000;

int eq(ll tot, ll a, ll p, ll q) {
	ll right = p * tot * (tot - 1);
	ll left = q * a * (a - 1);
	if (right == left)
		return 1;
	if (right > left)
		return 2;
	return 0;
}

ll valid(ll a, ll p, ll q) {
	ll s = 2, e = N;
	while (s < e) {
		ll mid = s + (e - s) / 2;
		(eq(mid, a, p, q)) ? e = mid : s = mid + 1;
	}
	return s;
}

int main() {
	ll p, q;
	while (scanf("%lld %lld", &p, &q) && p + q) {
		ll red = -1, tot = -1;
		for (int i = 0; i <= N; ++i) {
			ll tmp = valid(i, p, q);
			if (eq(tmp, i, p, q) == 1) {
				red = i, tot = tmp;
				break;
			}
		}
		if (red != -1) {
			printf("%lld %lld\n", red, tot - red);
		} else {
			puts("impossible");
		}
	}
	return 0;
}

