#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> sieve(ll n){
	vector <bool> is_prime (n+1,true);
	vector <ll> prime;
	for (int i=2;i<=n;++i){
		if (!is_prime[i]) continue;
		else {
			prime.push_back(i);
			for (int j=2;i*j<=n;++j){
				is_prime[i*j]=0;
			}
		}
	}
	return prime;
}

int main() {
	vector <ll> prime=sieve(10000000);
	return 0;
}
