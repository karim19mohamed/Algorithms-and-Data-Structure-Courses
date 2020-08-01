#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<int> v(n, 0);
		int ans = 1;
		bool change = 1;
		while (change) {
			change = 0;
			for (int i = 0; i < n; ++i) {
				if (v[i] == 0) {
					v[i] = ans++, change = 1;
					break;
				} else {
					int tmp = sqrt(ans + v[i]);
					if (tmp * tmp == ans + v[i]) {
						v[i] = ans++, change = 1;
						break;
					}
				}
			}
		}
		printf("%d\n", ans - 1);
		//for(int i=0;i<n;++i) dbg(v[i]);
	}
	return 0;
}

