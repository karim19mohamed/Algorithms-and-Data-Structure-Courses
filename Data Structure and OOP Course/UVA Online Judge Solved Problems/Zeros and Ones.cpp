#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n, a, b, arr[1000009], cs = 1;
	string s;
	while (cin >> s) {
		int tmp = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1')
				++tmp;
			arr[i] = tmp;
		}
		printf("Case %d:\n", cs++);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a, &b);
			int min_num = min(a, b), max_num = max(a, b);
			//dbg4(min_num,max_num,arr[min_num],arr[max_num]);
			if ((arr[max_num] - arr[min_num] == 0 && s[min_num] == '0')
					|| (arr[max_num] - arr[min_num] == max_num - min_num
							&& s[min_num] == '1'))
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}

