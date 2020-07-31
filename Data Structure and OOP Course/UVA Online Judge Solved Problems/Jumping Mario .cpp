#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,t,a,b,cs=1;
	scanf("%d",&t);
	while(t--){
		int high=0,low=0;
		scanf("%d",&n);
		scanf("%d",&a);
		for (int i=0;i<n-1;++i){
			scanf("%d",&b);
			if (b>a) ++high;
			else if (a>b) ++low;
			a=b;
		}
		printf("Case %d: %d %d\n",cs++,high,low);
	}
	return 0;
}

















