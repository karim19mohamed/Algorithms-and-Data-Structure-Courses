#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,t,a[29];
map <int,string> m;
int solve (int idx,int num,string s){
	if (idx==t){
		if (num<=n) m[num]=s;
		return (num<=n)? num : 0;
	}
	int res=max(solve(idx+1,num,s+"0"),solve(idx+1,num+a[idx],s+"1"));

	return res;
}


int main() {
	while (cin>>n){
		scanf("%d",&t);
		for (int i=0;i<t;++i) scanf("%d",&a[i]);
		int sum=solve(0,0,"");
		for (int i=0;i<m[sum].size();++i) if (m[sum][i]=='1') printf("%d ",a[i]);
		printf("sum:%d\n",sum);
	}
	return 0;
}
















