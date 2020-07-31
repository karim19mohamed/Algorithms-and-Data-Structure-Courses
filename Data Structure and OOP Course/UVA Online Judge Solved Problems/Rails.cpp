#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, arr[10000];
	while (scanf("%d", &n) && n) {
		while (scanf("%d", &arr[0]) && arr[0]) {
			queue<int> a;
			stack<int> b;
			for (int i = 1; i <= n; ++i)
				a.push(i);
			for (int i = 1; i < n; ++i)
				scanf("%d", &arr[i]);
			for (int i = 0; i < n; ++i) {
				if (b.empty()) {
					b.push(a.front());
					a.pop();
				}
				while (b.top() != arr[i] && !a.empty()) {
					b.push(a.front());
					a.pop();
				}
				if (b.top() == arr[i])
					b.pop();
				else
					break;
			}
			(a.empty() && b.empty()) ? puts("Yes") : puts("No");
		}
		printf("\n");
	}
	return 0;
}

