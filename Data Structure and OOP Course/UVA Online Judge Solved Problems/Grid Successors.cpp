#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int a[3][3],tmp[3][3],res[3][3];
void trans (){
	int f=0;
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			f=0;
			if (i-1>=0) f+=tmp[i-1][j];
			if (i+1<3) f+=tmp[i+1][j];
			if (j-1>=0) f+=tmp[i][j-1];
			if (j+1<3) f+=tmp[i][j+1];
			res[i][j]=f%2;
		}
	}
}
bool if_equal(){
	for (int i=0;i<3;++i) for (int j=0;j<3;++j){
		a[i][j]=tmp[i][j];
		tmp[i][j]=res[i][j];
	}
	for (int i=0;i<3;++i) for (int j=0;j<3;++j) if (a[i][j]!=res[i][j]) return false;
	return true;
}

int main() {
	int t;
	scanf("%d",&t);
	string s;
	while (t--){
		for (int i=0;i<3;++i){
			cin >> s;
			for (int j=0;j<3;++j) tmp[i][j]=a[i][j] = (s[j]=='1')? 1 : 0;
		}
		int ans=0;
		trans();
		while (!if_equal()){
			++ans;
			trans();
		}
		printf("%d\n",ans-1);
	}
	return 0;
}


















