#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> coprime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i){
		if (num%i==0){
			ll co_prime=1;
			while(num%i==0) co_prime*=i,num/=i;
			v.push_back(co_prime);
		}
	}
	if (num!=1) v.push_back(num);
	return v;
}
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
// modular of large number that can be calculated otherwise use euler-totient
// a^n mod m = ???
ll mod_large_num (ll a,ll n,ll m){
	vector <ll> a_chinese,n_chinese;
	n_chinese =  coprime_factorization(m);
	for (int i=0;i<(int)n_chinese.size();++i){
		a_chinese.push_back(mod_powered_num(a,n,n_chinese[i]));
	}
	ll ans=chinese_rem(a_chinese,n_chinese);
	return ans;
}

int main() {
	ll a=2,n=31,m=2925;
	ll ans = mod_large_num(a,n,m);
	dbg(ans);

	return 0;
}























