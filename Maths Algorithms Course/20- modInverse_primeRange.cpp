#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

// to solve inv[i]=(p - (p/i)*(inv[p%i]%p))%p
vector <ll> modInverse_primeRange(ll p){
	vector <ll> inv (p-1,1);
	for (ll i=2;i<p;++i) inv[i]=(p - (p/i)*(inv[p%i]%p))%p;
	return inv;
}

int main() {
	vector <ll> modInverse = modInverse_primeRange(7);
	for (ll i=1;i<modInverse.size();++i) dbg2(i,modInverse[i]);

	return 0;
}























