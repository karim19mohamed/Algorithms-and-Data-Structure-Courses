#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int GCD (int a,int b){ // a>b
	if (b==0) return a;
	return GCD (b,a%b);
}
int POW (int b,int p,int m){ // a>b
	if (p==0) return 1;
	int sq=POW(b,p/2,m);
	sq=(sq*sq)%m;
	if (p%2) sq=(sq*b)%m;
	return sq;
}
int EulerTotientFunction(int num){ //O(sqrt(n))
	int phi=1;
	for (int i=2;i*i<=num;++i){
		if (num%i==0){
			int k=1;
			while(num%i==0) k*=i,num/=i;
			phi *= (k/i)*(i-1);
		}
	}
	if (num!=1) phi*=(num-1);
	return phi;
}
vector <int> prime_factorization(int num){ //O(sqrt(n))
	vector <int> v;
	for (int i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}
// to solve (n^p)%m && n<m
int mod_powered_num(int n,int p,int m){
	if (GCD(n,m)>1){
		vector <int> prime_factors = prime_factorization(n);
		int ans=1;
		int phi = EulerTotientFunction(m);
		for (int i=0;i<(int)(prime_factors.size());++i){
			if (m%prime_factors[i]!=0){
				ans=(ans*POW(prime_factors[i],p%phi,m))%m;
			}else{
				int g=1,t=m/prime_factors[i];
				while (t%prime_factors[i]==0) ++g,t/=prime_factors[i];
				int phi_t = EulerTotientFunction(t);
				ans=(ans*POW(prime_factors[i],g,m)*POW(prime_factors[i],(p-g)%phi_t,m))%m;
			}
		}
		return ans;
	}
	int phi = EulerTotientFunction(m);
	return POW(n,p%phi,m);
}
map < pair<int,int>,int > dyn;
map < pair<int,int>,pair <int,int> > t_prime;
int mod_tower_power (vector<int> powers,int pos,int m){
	if (powers[pos]==1) return 1;

	int n=powers[pos];
	vector <int> prime_factors = prime_factorization(n);
	int ans=1;
	int phi = EulerTotientFunction(m);
	int p;
	for (int i=0;i<(int)(prime_factors.size());++i){
		if (m%prime_factors[i]!=0){
			p=mod_tower_power(powers,pos+1,phi);
			ans=(dyn.count({p,m})>0)? (ans*dyn[{p,m}])%m : (ans*POW(prime_factors[i],p%phi,m))%m;
		}else{
			int g=1,t=m/prime_factors[i];
			if (t_prime.count({t,prime_factors[i]})>0){
				t=t_prime[{t,prime_factors[i]}].first;
				g=t_prime[{t,prime_factors[i]}].second;
			}else{
				while (t%prime_factors[i]==0) ++g,t/=prime_factors[i];
				t_prime[{t,prime_factors[i]}]={t,g};
			}
			int phi_t = EulerTotientFunction(t);
			p=mod_tower_power(powers,pos+1,phi_t);
			ans=(dyn.count({p,m})>0)? (ans*dyn[{p,m}])%m : (ans*POW(prime_factors[i],g,m)*POW(prime_factors[i],(p-g)%phi_t,m))%m;
		}
	}
	dyn[{p,m}]=ans;
	return ans;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		int tmp,m;
		scanf("%d",&n);
		vector<int> p;
		for (int i=0;i<n;++i){
			scanf("%d",&tmp);
			p.push_back(tmp);
		}
		p.push_back(1);
		scanf("%d",&m);
		int ans=mod_tower_power(p,0,m);
		printf("%d\n",ans);
	}

	return 0;
}























