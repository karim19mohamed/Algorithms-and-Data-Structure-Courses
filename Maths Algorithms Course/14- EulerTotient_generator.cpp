#include <bits/stdc++.h>
typedef long long ll;
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

int main() {
	ll n=10;
	vector <ll> phi = EulerTotient_generator(n);
	for (int i=0;i<phi.size();++i) dbg2(i,phi[i]);

	return 0;
}























