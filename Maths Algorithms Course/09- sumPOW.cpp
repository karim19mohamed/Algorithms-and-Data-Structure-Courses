#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll half_k[100000];
ll sumPOW(ll a,ll k){
	if (k==0) return 0;
	if (half_k[k]) return half_k[k];
	if (k%2) return a*(1+sumPOW(a,k-1));

	ll half = sumPOW(a,k/2);
	half_k[k/2]=half,half_k[(k/2)+1]=a*(1+half);
	return half*(1+half-sumPOW(a,(k/2)-1));
}

int main() {
	ll a=5,k=11;
	cout << sumPOW(a,k) << endl;
	//for (ll i=0;i<11;++i) dbg2(i,half_k[i]);
	return 0;
}























