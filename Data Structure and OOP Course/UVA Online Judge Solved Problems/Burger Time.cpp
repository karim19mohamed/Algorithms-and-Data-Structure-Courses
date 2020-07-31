#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int l;
	string s;
	while (cin>>l && l){
		cin >> s;
		int ans=10000000,d,r;
		bool a=0,b=0;
		for (int i=0;i<l;++i){
			if (s[i]=='.') continue;
			else if (s[i]=='D') d=i,a=1;
			else if (s[i]=='R') r=i,b=1;
			else if (s[i]=='Z'){
				ans=0;
				break;
			}
			if (a && b) ans=min(ans,abs(d-r));
		}
		printf("%d\n",ans);
	}
	return 0;
}


















