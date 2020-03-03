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

int main() {
	cout << LCM(50,30) << endl;
	return 0;
}









