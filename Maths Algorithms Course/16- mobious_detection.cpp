#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll mobious_detection(ll n){
	ll mob=1;
	for (ll i=2;i*i<=n;++i){
		if (n%i==0){
			if (n%(i*i)==0) return 0;
			n/=i,mob=-mob;
		}
	}
	if (n>1) mob=-mob;
	return mob;
}

int main() {
	ll n=10,ans;
	for (ll i=1;i<n;++i) ans=mobious_detection(i),dbg2(i,ans);

	return 0;
}























