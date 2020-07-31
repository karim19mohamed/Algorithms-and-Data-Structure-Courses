#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2 && x1 && x2 && y1 && y2){
		int ans;
		if (x1==x2 && y1==y2) ans=0;
		else if (x1==x2 || y1==y2) ans=1;
		else if (x1-y1==x2-y2 || x1+y1==x2+y2) ans=1;
		else ans=2;
		printf("%d\n",ans);
	}
	return 0;
}


















