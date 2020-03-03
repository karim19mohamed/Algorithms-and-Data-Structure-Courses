#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll POW (ll b,ll p,ll m){ // a>b
	if (p==0) return 1;
	ll sq=POW(b,p/2,m);
	sq=(sq*sq)%m;
	if (p%2) sq=(sq*b)%m;
	return sq;
}
ll EulerTotientFunction(ll num){ //O(sqrt(n))
	ll phi=1;
	for (ll i=2;i*i<=num;++i){
		if (num%i==0){
			ll k=1;
			while(num%i==0) k*=i,num/=i;
			phi *= (k/i)*(i-1);
		}
	}
	if (num!=1) phi*=(num-1);
	return phi;
}
// to solve a = a^(m-2) (mod m)
ll modInverse_euler_prime(ll a,ll m){
	return POW(a,m-2,m);
}
// to solve a = a^(phi(m)-1) (mod m)
ll modInverse_euler(ll a,ll m){
	return POW(a,EulerTotientFunction(m)-1,m);
}

int main() {
	ll a=8,m=11;
	ll ans= modInverse_euler(a,m);
	dbg3(a,m,ans);

	return 0;
}























