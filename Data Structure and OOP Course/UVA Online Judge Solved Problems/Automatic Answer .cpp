#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,n,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=(n*63+7492)*5-498;
		ans/=10;
		ans%=10;
		(ans<0)? printf("%d\n",ans*-1):printf("%d\n",ans);
	}
	return 0;
}

















