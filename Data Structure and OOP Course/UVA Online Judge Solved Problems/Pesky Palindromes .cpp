#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool palindrome_check (string s){
	string tmp="";
	for (int i=s.size()-1;i>=0;--i) tmp+=s[i];
	return (s==tmp)?  true : false;
}

int main() {
	string s;
	while(cin>>s){
		int ans=0;
		map <string,bool> m;
		for (int i=0;i<s.size();++i){
			string tmp="";
			tmp+=s[i];
			if (m.count(tmp)==0) ++ans;
			m[tmp]=1;
			for (int j=i+1;j<s.size();++j){
				tmp+=s[j];
				//dbg(tmp);
				if (palindrome_check(tmp) && m.count(tmp)==0) ++ans;
				m[tmp]=1;
			}
		}
		cout << "The string '" << s << "' contains " << ans << " palindromes." << endl;

	}
	return 0;
}

















