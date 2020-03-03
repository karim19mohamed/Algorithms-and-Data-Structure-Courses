#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll extend_GCD(ll a,ll b,ll &x,ll &y){ // a>b
	if (a<0){
		ll r = extend_GCD(-1*a,b,x,y);
		x*=-1;
		return r;
	}
	if (b<0){
		ll r = extend_GCD(a,-1*b,x,y);
		y*=-1;
		return r;
	}
	if (b==0){
		x=1,y=0;
		return a;
	}
	ll gcd = extend_GCD(b,a%b,y,x);
	// now x = y_previous & y = x_previous
	// calculate y = x_previous - (a/b) * y_previous
	y-=(a/b)*x;
	return gcd;
}
// to solve ax = 1 (mod m)
ll modInverse(ll a,ll m){
	ll x,y;
	ll gcd=extend_GCD(a,m,x,y);
	if (gcd!=1) return -1;
	return (x+m)%m;
}

int main() {
	ll a=8,m=11;
	ll ans= modInverse(a,m);
	dbg3(a,m,ans);

	return 0;
}























