#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
	string s;
	while(cin>>s && s[0]!='#'){
		bool ans=0;
		int idx_least_from_left,idx_first_greater_from_right,sz=s.size();
		for (int i=0;i<s.size();++i){
			for (int j=s.size()-1;j>i;--j){
				if (s[i]<s[j]){
					idx_least_from_left=i;
					idx_first_greater_from_right=j;
					ans=1;
					break;
				}
			}
		}
		swap(s[idx_least_from_left],s[idx_first_greater_from_right]);
		sort(s.begin()+idx_least_from_left+1,s.begin()+sz);
		if (ans) cout<<s<<endl;
		else puts("No Successor");
	}
	return 0;
}



















