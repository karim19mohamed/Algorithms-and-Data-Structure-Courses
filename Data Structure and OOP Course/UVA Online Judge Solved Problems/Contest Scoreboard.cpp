#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

using namespace std;
const int N = 100 + 9, M = 9 + 9;
int sum_solved[N], sum_pen[N], prob_pen[N][M];
bool teams[N], solved[N][M];

void reset() {
	memset(teams, 0, sizeof(teams));
	memset(sum_solved, 0, sizeof(sum_solved));
	memset(sum_pen, 0, sizeof(sum_pen));
	for (int i = 0; i < N; ++i) {
		memset(solved[i], 0, sizeof(solved[i]));
		memset(prob_pen[i], 0, sizeof(prob_pen[i]));
	}
}

// contestant problem time L
// contestant num_solved time_penality
int main() {
	int t, contestant, prob, time;
	string s;
	char L;
	scanf("%d", &t);
	getline(std::cin, s);
	getline(std::cin, s);
	while (t--) {
		reset();
		while (getline(std::cin, s) && s.size()) {
			stringstream in(s);
			in >> contestant >> prob >> time >> L;
			teams[contestant] = 1;
			if (L == 'C' && !solved[contestant][prob]) {
				solved[contestant][prob] = 1;
				++sum_solved[contestant];
				sum_pen[contestant] += time + prob_pen[contestant][prob];
			} else if (L == 'I' && !solved[contestant][prob]) {
				prob_pen[contestant][prob] += 20;
			}
		}
		priority_queue<pair<pair<int, int>, int> > ans;
		for (int i = 0; i < N; ++i) {
			if (teams[i]) {
				ans.push( { { sum_solved[i], -sum_pen[i] }, -i });
			}
		}
		while (!ans.empty()) {
			contestant = -ans.top().second;
			prob = ans.top().first.first;
			time = -ans.top().first.second;
			ans.pop();
			printf("%d %d %d\n", contestant, prob, time);
		}
		if (t)
			puts("");
	}
	return 0;
}

