#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

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

int main() {
	ll n=2*3*4*5*6*7*8*9*10;
	dbg2(n,EulerTotientFunction(n));
	return 0;
}























