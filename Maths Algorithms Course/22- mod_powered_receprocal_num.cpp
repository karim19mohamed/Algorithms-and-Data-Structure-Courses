#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll GCD (ll a,ll b){ // a>b
	if (b==0) return a;
	return GCD (b,a%b);
}
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
// to solve ((1/a)^m)%p and p is primes
ll mod_prime_powered_receprocal_num(ll a,ll m,ll p){
	return POW(a,( (p-1)-m%(p-1) )%(p-1),p);
}
// to solve ((1/a)^m)%p and p is not primes
ll mod_powered_receprocal_num(ll a,ll m,ll p){
	if (GCD(a,p)!=1) return -1;
	ll phi = EulerTotientFunction(p);
	return POW(a,(phi-1)*m,p);
}
int main() {
	ll a=25 , m=547 , p=14;
	ll ans = mod_powered_receprocal_num(a,m,p);
	dbg4(1/a,m,p,ans);

	return 0;
}























