#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,dd,mm,year;
	scanf("%d",&n);
	string s;
	priority_queue < pair< pair< pair<int,int> ,int> ,string> > q;
	while (n--){
		cin >> s;
		scanf("%d %d %d",&dd,&mm,&year);
		q.push({{{year,mm},dd},s});
	}
	s=q.top().second;
	q.pop();
	cout << s << endl;
	while(!q.empty()){
		s=q.top().second;
		q.pop();
	}
	cout << s << endl;
	return 0;
}


















