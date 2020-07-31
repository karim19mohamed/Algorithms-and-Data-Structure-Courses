#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,a[3009];
	while(cin>>n){
		bool ans=1;
		vector <bool> v(n,0);
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if (i>0) v[abs(a[i]-a[i-1])]=1;
		}
		for (int i=1;i<n;++i)
			if (!v[i]){
				ans=0;
				break;
			}
		(ans) ? puts("Jolly") : puts("Not jolly");
	}
	return 0;
}


















