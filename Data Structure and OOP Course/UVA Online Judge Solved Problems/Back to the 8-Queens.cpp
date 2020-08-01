#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool row[10], col[10], dig1[20], dig2[20];
int solution[10], all_sol[10][1000], num_sol, mb[10], ans, cs = 1;

bool attacked(int x, int y) {
	return (row[x] || col[y] || dig1[x + y] || dig2[x - y + 8]) ? 1 : 0;
}
void set_queen(int x, int y) {
	row[x] = col[y] = dig1[x + y] = dig2[x - y + 8] = 1;
	solution[y] = x + 1;
}
void unset_queen(int x, int y) {
	row[x] = col[y] = dig1[x + y] = dig2[x - y + 8] = 0;
}
void print_solution() {
	for (int i = 0; i < 8; ++i)
		all_sol[i][num_sol] = solution[i];
	++num_sol;
}

void solve(int q, int col) {
	if (col == 8) {
		if (q == 8)
			print_solution();
		return;
	}
	for (int i = 0; i < 8; ++i) {
		if (!attacked(i, col)) {
			set_queen(i, col);
			solve(q + 1, col + 1);
			unset_queen(i, col);
		}
	}
}
void cal_min() {
	for (int i = 0; i < num_sol; ++i) {
		int tmp = 0;
		for (int j = 0; j < 8; ++j) {
			tmp += (mb[j] != all_sol[j][i]);
		}
		ans = min(ans, tmp);
	}
}

int main() {
	solve(0, 0);
	while (scanf("%d %d %d %d %d %d %d %d", &mb[0], &mb[1], &mb[2], &mb[3],
			&mb[4], &mb[5], &mb[6], &mb[7]) == 8) {
		ans = 16777216;
		cal_min();
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}

