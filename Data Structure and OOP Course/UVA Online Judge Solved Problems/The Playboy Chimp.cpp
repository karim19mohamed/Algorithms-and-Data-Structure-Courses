#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll n,q,a[50009],b;
bool valid1(ll mid){
	return (a[mid]<b);
}
bool valid2(ll mid){
	return (a[mid]>b);
}

int main() {
	scanf("%lld",&n);
	for (ll i=0;i<n;++i) scanf("%lld",&a[i]);
	scanf("%lld",&q);
	for (ll i=0;i<q;++i){
		scanf("%lld",&b);
		ll ans1,ans2;

		ll st=0,et=n-1;
		while(st<et){
			ll mid=st+(et-st+1)/2;
			(valid1(mid))? st=mid : et=mid-1;
		}
		ans1=st;
		st=0,et=n-1;
		while(st<et){
			ll mid=st+(et-st)/2;
			(valid2(mid))? et=mid : st=mid+1;
		}
		ans2=st;
		(valid1(ans1))? printf("%lld ",a[ans1]):printf("X ");
		(valid2(ans2))? printf("%lld\n",a[ans2]):printf("X\n");
	}
	return 0;
}




















