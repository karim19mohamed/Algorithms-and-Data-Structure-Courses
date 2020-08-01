#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int a[5], vis[5];
bool solve(int num, int idx) {
	if (idx == 5) {
		//dbg(num);
		if (num == 23)
			return 1;
		return 0;
	}
	int res = 0;
	for (int i = 0; i < 5; ++i) {
		if (vis[i])
			continue;
		vis[i] = 1;
		res += solve(num + a[i], idx + 1);
		if (idx != 0) {
			res += solve(num - a[i], idx + 1);
			res += solve(num * a[i], idx + 1);
		}
		vis[i] = 0;
	}
	return res > 0;
}

int main() {

	while (1) {
		int idx = 0;
		for (int i = 0; i < 5; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == 0)
				++idx;
		}
		if (idx == 5)
			break;
		(solve(0, 0)) ? puts("Possible") : puts("Impossible");
	}
	return 0;
}

