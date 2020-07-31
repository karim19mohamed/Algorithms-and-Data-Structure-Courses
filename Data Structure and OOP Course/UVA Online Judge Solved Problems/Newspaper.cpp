#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n,k,m;
	ll p;
	char c;
	string s;
	scanf("%d",&n);
	while(n--){
		ll ans=0;
		scanf("%d",&k);
		vector <ll> price (300,0);
		for (int i=0;i<k;++i){
			scanf(" %c %lld",&c,&p);
			price[c+128]=p;
		}
		scanf("%d",&m);
		getline(std::cin,s);
		for (int i=0;i<m;++i){
			getline(std::cin,s);
			for (int j=0;j<s.size();++j){
				if (s[j]!=' ' && price[s[j]+128]) ans+=price[s[j]+128];
			}
		}
		long double f=(long double)(ans)/100;
		printf("%.2llf$\n",f);
	}
	return 0;
}


















