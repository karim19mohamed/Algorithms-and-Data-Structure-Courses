#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

// Given a prime n what is the count of numbers that is divisable by m and in range [1,n]

ll n,m,cnt;
int main() {
	n=1000000000;
	m=23;
	for (int i=2;i<n;++i) if (i%m==0) cnt++;
	dbg(cnt);
	dbg(n/m);
	return 0;
}









