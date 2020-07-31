#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll reverse_and_sum (ll n){
	ll ans=n,tmp=1;
	string s=to_string(n);
	for (int i=0;i,i<s.size();++i){
		ans+=(s[i]-'0')*tmp;
		tmp*=10;
	}
	return ans;
}
bool palindrom_check (ll n){
	string s=to_string(n);
	ll tmp,idx=0;
	while (n!=0){
		tmp=n%10;
		if (tmp!=(s[idx]-'0')) return false;
		n/=10;
		++idx;
	}
	return true;
}

int main() {
	int t;
	ll n;
	scanf("%d",&t);
	while (t--){
		scanf("%lld",&n);
		ll num_iteration=0;
		while (!palindrom_check(n)){
			n=reverse_and_sum(n);

			++num_iteration;
		}
		printf("%lld %lld\n",num_iteration,n);
	}
	return 0;
}

















