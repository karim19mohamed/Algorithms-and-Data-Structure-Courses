#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n;
	string s,choices[2]={"one","two"};
	scanf("%d",&n);
	while(n--){
		cin >> s;
		int a[2]={0,0};
		if (s.size()==5){
			puts("3");
		}else{
			for (int i=0;i<2;++i) for (int j=0;j<3;++j) if (choices[i][j]==s[j]) ++a[i];
			(a[0]>a[1])? puts("1") : puts("2");
		}
	}
	return 0;
}


















