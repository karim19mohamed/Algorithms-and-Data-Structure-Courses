#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int t,n,h;
void solve(string s,int num,int ones){
	if(num==n){
		if (ones==h) cout<<s<< endl;
		return;
	}
	solve(s+"0",num+1,ones);
	if(ones<h) solve(s+"1",num+1,ones+1);
}


int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&h);
		solve("",0,0);
		if(t) puts("");
	}

	return 0;
}










