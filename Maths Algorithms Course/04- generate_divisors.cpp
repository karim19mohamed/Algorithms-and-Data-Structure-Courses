#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <ll> generate_divisors(ll num){
	vector <ll> v;
	ll i;
	for (i=1;i*i<num;++i) if (num%i==0) v.push_back(i),v.push_back(num/i);
	if (i*i==num) v.push_back(i);
	return v;
}

int main() {
	vector <ll> divisors = generate_divisors(20);
	for (int i=0;i<divisors.size();++i) dbg(divisors[i]);
	return 0;
}









