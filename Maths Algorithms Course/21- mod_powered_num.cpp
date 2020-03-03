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
vector <ll> prime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}
// to solve (n^p)%m && n<m
ll mod_powered_num(ll n,ll p,ll m){
	if (GCD(n,m)>1){
		vector <ll> prime_factors = prime_factorization(n);
		ll ans=1;
		ll phi = EulerTotientFunction(m);
		for (int i=0;i<(int)(prime_factors.size());++i){
			if (m%prime_factors[i]!=0){
				ans=(ans*POW(prime_factors[i],p%phi,m))%m;
			}else{
				ll g=1,t=m/prime_factors[i];
				while (t%prime_factors[i]==0) ++g,t/=prime_factors[i];
				ll phi_t = EulerTotientFunction(t);
				ans=(ans*POW(prime_factors[i],g,m)*POW(prime_factors[i],(p-g)%phi_t,m))%m;
			}
		}
		return ans;
	}
	ll phi = EulerTotientFunction(m);
	return POW(n,p%phi,m);
}

int main() {
	ll n=140 , p=222 , m=70;
	ll ans = mod_powered_num(n,p,m);
	dbg4(n,p,m,ans);

	return 0;
}























