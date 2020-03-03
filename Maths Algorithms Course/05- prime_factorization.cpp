#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> prime_factorization(ll num){ //O(sqrt(n))
	vector <ll> v;
	for (ll i=2;i*i<=num;++i) while(num%i==0) v.push_back(i),num/=i;
	if (num!=1) v.push_back(num);
	return v;
}

int main() {
	vector <ll> prime_factors = prime_factorization(100);
	for (int i=0;i<prime_factors.size();++i) dbg(prime_factors[i]);
	return 0;
}









