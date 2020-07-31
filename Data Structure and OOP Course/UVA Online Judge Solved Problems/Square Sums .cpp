#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,a[10][10],ans[5],cse=1;
	while(cin>>n && n){
		memset(ans,0,sizeof(ans));
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) scanf("%d",&a[i][j]);
		for (int i=0;i<n/2;++i){
			for (int j=i;j<n-i;++j){
				//dbg4(i,j,a[i][j],a[j][n-1-i]);
				ans[i]+=a[i][j]+a[n-1-i][j];
				if (j!=n-1-i && j!=i) ans[i]+=a[j][i]+a[j][n-1-i];
			}
		}
		printf("Case %d:",cse++);
		for (int i=0;i<n/2;++i){
			printf(" %d",ans[i]);
		}
		(n%2)? printf(" %d\n",a[n/2][n/2]):printf("\n");
	}
	return 0;
}

















