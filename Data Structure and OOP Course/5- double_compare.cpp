#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool double_compare(int a,double b){
	// fair comparison without subtracting any digit from b
	double tmp=(b+(1e-6))*1000000.0;
	ll tmp2=tmp,tmp3=(ll)a*1000000;
	return tmp3>tmp2;
}

int main() {
	int a;
	double b;
	scanf("%d %lf",&a,&b);
	cout << double_compare(a,b) << endl;
	return 0;
}


















