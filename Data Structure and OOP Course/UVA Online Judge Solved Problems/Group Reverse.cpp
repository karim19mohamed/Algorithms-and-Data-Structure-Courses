#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int n;
	string s;
	stack <char> rev;
	while(cin>>n && n){
		cin >> s;
		string ans="";
		int group_size = s.size()/n;
		for (int i=0;i<s.size();++i){
			rev.push(s[i]);
			if ((i+1)%group_size==0){
				while (!rev.empty()){
					ans+=rev.top();
					rev.pop();
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


















