#include <bits/stdc++.h>
typedef unsigned long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll valid (ll c,ll p){
	ll s=2,e=50000;
	while(s<e){
		ll mid=s+(e-s+1)/2;
		(p*mid*mid<=p*mid+c)? s=mid : e=mid-1 ;
	}
	return (p*s*s==p*s+c)? s : 0;
}


int main() {
	ll p,q;
	while (cin>>p>>q && p+q){
		if (p==0){
			printf("0 2\n");
			continue;
		}
		ll x,z;
		bool ans;
		for (ll i=1;i<=50000LL;++i){
			x=i;
			ll c=x*(x-1)*q;
			z=valid(c,p);
			if(z!=0){
				ans=1;
				break;
			}
		}
		(ans && z<=50000 && z>=2)? printf("%llu %llu\n",x,z-x) : puts("impossible");
	}
	return 0;
}
















