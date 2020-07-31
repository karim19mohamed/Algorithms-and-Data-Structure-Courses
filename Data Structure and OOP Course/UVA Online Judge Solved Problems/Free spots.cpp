#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int w,h,n;
	ll a[509][509],c=1;
	for (int i=0;i<509;++i) memset(a[i], 0, sizeof(a[i]));
	while (cin>>w>>h>>n && w && h){
		int x1,y1,x2,y2,x_min,x_max,y_min,y_max,ans=0;
		for (int i=0;i<n;++i){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x_min=min(x1,x2); x_max=max(x1,x2);
			y_min=min(y1,y2); y_max=max(y1,y2);
			for (int j=x_min-1;j<x_max;++j) for (int k=y_min-1;k<y_max;++k) a[j][k]=c;
		}
		for (int i=0;i<w;++i){
			for (int j=0;j<h;++j){
				if (a[i][j]!=c) ++ans;
			}
		}
		if (ans==0) puts("There is no empty spots.");
		else if (ans==1) puts("There is one empty spot.");
		else printf("There are %d empty spots.\n",ans);
		++c;
	}
	return 0;
}


















