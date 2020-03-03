#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

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

// solve the equation ax = b (mod n) => ax-b=ny => ax-ny=b
vector <ll> modularEquation(ll a,ll b,ll n){
	vector <ll> solution;
	ll x,y;
	ll gcd = extend_GCD(a,-1*n,x,y);
	x=( ( (x*b/gcd)%n )+n )%n;
	for (ll i=0;i<gcd;++i){
		solution.push_back( ( x+i*(n/gcd) )%n );
	}
	return solution;
}


int main() {
	ll a=258,n=147,b=369,x,y;
	vector <ll> solution = modularEquation(a,b,n);
	dbg3(a,b,n);
	for (int i=0;i<solution.size();++i) dbg2(solution[i],a);
	return 0;
}























