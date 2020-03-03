#include <bits/stdc++.h>
typedef int ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> EulerTotient_generator(ll n){
	vector <bool> is_prime (n+1,true);
	vector <ll> phi (n+1,true);
	for (ll i=2;i<=n;++i){
		if (!is_prime[i]) continue;
		else {
			phi[i]=i-1;
			for (ll j=2;i*j<=n;++j){
				is_prime[i*j]=0;
				ll k=1,num=i*j;
				while(num%i==0) k*=i,num/=i;
				phi[i*j] *= (k/i)*(i-1);
			}
		}
	}
	return phi;
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
vector <ll> prime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}

map < pair<ll,ll>,ll > dyn;
map < pair<ll,ll>,pair <ll,ll> > t_prime;
int mod_tower_power (vector<ll> powers,ll pos,ll m,vector <ll> phi_tot){
	if (powers[pos]==1) return 1;

	ll n=powers[pos];
	vector <ll> prime_factors = prime_factorization(n);
	ll ans=1;
	ll phi = phi_tot[m];
	ll p;
	for (int i=0;i<(int)(prime_factors.size());++i){
		if (m%prime_factors[i]!=0){
			p=mod_tower_power(powers,pos+1,phi,phi_tot);
			ans=(dyn.count({p,m})>0)? (ans*dyn[{p,m}])%m : (ans*POW(prime_factors[i],p%phi,m))%m;
		}else{
			ll g=1,t=m/prime_factors[i];
			if (t_prime.count({t,prime_factors[i]})>0){
				t=t_prime[{t,prime_factors[i]}].first;
				g=t_prime[{t,prime_factors[i]}].second;
			}else{
				while (t%prime_factors[i]==0) ++g,t/=prime_factors[i];
				t_prime[{t,prime_factors[i]}]={t,g};
			}
			ll phi_t = phi_tot[t];
			p=mod_tower_power(powers,pos+1,phi_t,phi_tot);
			ans=(dyn.count({p,m})>0)? (ans*dyn[{p,m}])%m : (ans*POW(prime_factors[i],g,m)*POW(prime_factors[i],(p-g)%phi_t,m))%m;
		}
	}
	dyn[{p,m}]=ans;
	return ans;
}

int main() {
	ll t=1;
	scanf("%d",&t);
	vector <ll> phi = EulerTotient_generator(1000001);
	while (t--){
		ll n;
		ll tmp,m;
		scanf("%d",&n);
		vector<ll> p;
		for (ll i=0;i<n;++i){
			scanf("%d",&tmp);
			p.push_back(tmp);
		}
		p.push_back(1);
		scanf("%d",&m);
		ll ans=mod_tower_power(p,0,m,phi);
		printf("%d\n",ans);
	}

	return 0;
}























