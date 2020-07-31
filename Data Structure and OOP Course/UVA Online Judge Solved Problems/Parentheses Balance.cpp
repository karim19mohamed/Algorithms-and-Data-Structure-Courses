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
	scanf("%d",&n);
	getline(std::cin,s);
	while(n--){
		getline(std::cin,s);
		bool ans=1;
		stack <char> chk;
		for (int i=0;i<s.size();++i){
			if (s[i]=='(' || s[i]=='[') chk.push(s[i]);
			else if (s[i]==')' || s[i]==']'){
				if (chk.empty() || (chk.top()!='[' && s[i]==']') || (chk.top()!='(' && s[i]==')') ){
					ans=0;
					break;
				}
				chk.pop();
			}
		}
		(ans && chk.empty())? puts("Yes") : puts("No");
	}
	return 0;
}
