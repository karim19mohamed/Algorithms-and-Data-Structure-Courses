#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

// Given a prime p and n what is the max x that p^x divides n!
ll FactN_PrimePower(ll n,ll p){
	ll pow=0;
	for(ll i=p;i<=n;i*=p) pow+=n/i;
	return pow;
}


ll n,p=2;
int main() {
	n=10;
	cout << FactN_PrimePower(n,p) << endl;

	return 0;
}









