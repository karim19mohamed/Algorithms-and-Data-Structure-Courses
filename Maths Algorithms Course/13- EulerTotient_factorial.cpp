#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool is_prime(ll n){
	if (n==2) return true;
	if (n<2 || n%2==0) return false;
	for (ll i=3;i*i<=n;i+=2){
		if (n%i==0) return false;
	}
	return true;
}

ll EulerTotient_factorial(ll n){
	ll phi=1;
	for (ll i=2;i<=n;++i) phi *= (is_prime(i))? i-1 : i;
	return phi;
}

int main() {
	ll n=10,ans;
	ans= EulerTotient_factorial(n);
	dbg2(n,ans);

	return 0;
}























