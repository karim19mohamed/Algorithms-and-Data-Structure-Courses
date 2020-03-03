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
// x = a (mod n)
ll chinese_rem (vector <ll> a,vector <ll> n){
	ll prod_n=1,x=0;
	for (auto i : n) prod_n*=i;
	for (ll i=0;i<(ll)n.size();++i){
		x+=a[i]*modInverse(prod_n/n[i],n[i])*prod_n/n[i];
	}
	return x%prod_n;
}

int main() {
	vector <ll> a,n;
	a.push_back(2),a.push_back(3),a.push_back(1);
	n.push_back(3),n.push_back(4),n.push_back(5);
	ll ans = chinese_rem (a,n);
	dbg(ans);

	return 0;
}























