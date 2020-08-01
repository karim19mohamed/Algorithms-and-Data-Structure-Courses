#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,a[10009],m;
	while(scanf("%d",&n)==1){
		vector<bool> vis(1000009,false);
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		}
		scanf("%d",&m);
		int ans1=0,ans2=10000009;
		for (int i=0;i<n;++i){
			int diff=m-a[i];
			if(diff>=0 && vis[diff] && abs(a[i]-diff)<ans2-ans1) ans2=max(a[i],diff),ans1=min(a[i],diff);
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
	}
	return 0;
}


















