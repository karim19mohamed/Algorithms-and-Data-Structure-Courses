#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll GCD (ll a,ll b){ // a>b
	if (b==0) return a;
	return GCD (b,a%b);
}

ll LCM (ll a,ll b){
	return a*b/GCD(a,b);
}
ll extend_GCD(ll a,ll b,ll &x,ll &y){ // a>b
	if (a<0){
		ll r = extend_GCD(-1*a,b,x,y);
		x*=-1;
		return r;
	}
	if (b<0){
		ll r = extend_GCD(a,-1*b,x,y);
		y*=-1;
		return r;
	}
	if (b==0){
		x=1,y=0;
		return a;
	}
	ll gcd = extend_GCD(b,a%b,y,x);
	// now x = y_previous & y = x_previous
	// calculate y = x_previous - (a/b) * y_previous
	y-=(a/b)*x;
	return gcd;
}
ll ldioph (ll a,ll b,ll c,ll &x,ll &y,bool &found){
	ll gcd = extend_GCD(a,b,x,y);
	if (found=c%gcd==0){
		x*=c/gcd,y*=c/gcd;
	}
	return gcd;
}
// T = x (mod N) & T = y (mod M)
// x+kN=y+pM --> kN-pM=y-x --> T=x+kN --> T = (x+kN) (mod LCM(N,M))
ll general_solution_rem (vector <ll> a,vector <ll> n){
	ll N=n[0],x=a[0],M,y;
	for (ll i=1;i<(ll)n.size();++i){
		bool found;
		ll k,p;
		M=n[i],y=a[i];
		ll gcd = ldioph(N,-M,y-x,k,p,found);
		x=x+k*N;
		N=N*M/gcd;
		x=(N+x)%N;
	}
	return x;
}

int main() {
	vector <ll> a,n;
	a.push_back(2),a.push_back(3),a.push_back(1);
	n.push_back(3),n.push_back(4),n.push_back(5);
	ll ans = general_solution_rem (a,n);
	dbg(ans);

	return 0;
}























