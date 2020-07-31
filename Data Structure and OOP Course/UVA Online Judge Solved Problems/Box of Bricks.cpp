#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, h[59], cs = 1;
	while (cin >> n && n) {
		int avg = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &h[i]);
			avg += h[i];
		}
		avg /= n;
		for (int i = 0; i < n; ++i)
			if (h[i] > avg)
				ans += (h[i] - avg);
		printf("Set #%d\n", cs++);
		printf("The minimum number of moves is %d.\n\n", ans);
	}
	return 0;
}

