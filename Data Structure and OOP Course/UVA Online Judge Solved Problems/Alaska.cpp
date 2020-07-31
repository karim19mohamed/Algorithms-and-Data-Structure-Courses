#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, a[1500];
	while (cin >> n && n) {
		bool ans = 1;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 1; i < n; ++i) {
			if (a[i] - a[i - 1] > 200) {
				ans = 0;
				break;
			}
		}
		if ((1422 - a[n - 1]) * 2 > 200)
			ans = 0;
		(ans) ? puts("POSSIBLE") : puts("IMPOSSIBLE");
	}
	return 0;
}

