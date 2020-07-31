#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n;
	queue<int> q;
	while (cin >> n && n) {
		for (int i = 1; i <= n; ++i)
			q.push(i);
		int a, b;
		printf("Discarded cards:");
		while (q.size() > 2) {
			a = q.front(), q.pop();
			b = q.front(), q.pop();
			printf(" %d,", a);
			q.push(b);
		}
		if (q.size() == 2) {
			a = q.front(), q.pop();
			b = q.front(), q.pop();
			printf(" %d\n", a);
			printf("Remaining card: %d\n", b);
		} else if (q.size() == 1) {
			a = q.front(), q.pop();
			printf("\n");
			printf("Remaining card: %d\n", a);
		}

	}
	return 0;
}
