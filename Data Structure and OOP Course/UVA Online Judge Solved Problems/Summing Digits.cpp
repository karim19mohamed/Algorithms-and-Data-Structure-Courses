#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	string s;
	while (cin>>s && s!="0"){
		int ans=0;
		for (int i=0;i<s.size();++i) ans+=(s[i]-'0');
		while (ans/10!=0){
			int tmp=ans;
			ans=0;
			while (tmp!=0){
				ans+=tmp%10;
				tmp/=10;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

















