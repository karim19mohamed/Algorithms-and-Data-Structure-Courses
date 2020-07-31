#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,a[10],order[10],order_reversed[10];
	scanf("%d",&t);
	puts("Lumberjacks:");
	while(t--){
		bool ans1=1,ans2=1;
		for (int i=0;i<10;++i){
			scanf("%d",&a[i]);
			order[i]=a[i];
			order_reversed[i]=-a[i];
		}
		sort(order,order+10);
		sort(order_reversed,order_reversed+10);
		for (int i=0;i<10;++i) if (order[i]!=a[i]) ans1=0;
		for (int i=0;i<10;++i) if (order_reversed[i]!=-a[i]) ans2=0;
		(ans1 || ans2) ? puts("Ordered") : puts("Unordered");
	}
	return 0;
}

















