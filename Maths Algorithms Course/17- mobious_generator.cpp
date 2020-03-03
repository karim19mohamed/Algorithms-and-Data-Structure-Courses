#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> mobious_generator(ll n){
	vector <bool> is_prime (n+1,true);
	vector <ll> mob (n+1,true);
	for (ll i=2;i<=n;++i){
		if (!is_prime[i]) continue;
		else {
			mob[i]=-mob[i];
			for (ll j=2;i*j<=n;++j){
				is_prime[i*j]=0;
				mob[i*j] = ((i*j)%(i*i)==0)? 0 : -mob[i*j];
			}
		}
	}
	return mob;
}

int main() {
	ll n=10;
	vector <ll> mob = mobious_generator(n);
	for (int i=0;i<mob.size();++i) dbg2(i,mob[i]);

	return 0;
}























