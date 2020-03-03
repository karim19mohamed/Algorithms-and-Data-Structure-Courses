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
ll ldioph (ll a,ll b,ll c,ll &x,ll &y,bool &found){
	ll gcd = extend_GCD(a,b,x,y);
	if (found=c%gcd==0){
		x*=c/gcd,y*=c/gcd;
	}
	return gcd;
}


int main() {
	ll a=258,b=147,c=369,x,y;
	bool found;
	ll gcd = ldioph(a,b,c,x,y,found);
	dbg4(a,b,x,y);
	dbg3(c,gcd,found);
	gcd = ldioph(-1*a,b,c,x,y,found);
	dbg4(-1*a,b,x,y);
	dbg3(c,gcd,found);
	return 0;
}























