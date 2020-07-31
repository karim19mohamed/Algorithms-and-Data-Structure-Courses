#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	ll n,sz,med;
	vector <ll> a;
	while (cin>>n){
		a.push_back(n);
		sz=a.size();
		sort(a.begin(),a.begin()+sz);
		(sz%2)? med = a[sz/2] : med = (a[sz/2] + a[(sz/2)-1])/2;
		printf("%lld\n",med);
	}
	return 0;
}

















