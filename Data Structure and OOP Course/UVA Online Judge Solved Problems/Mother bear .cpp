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
	while(1){
		getline (std::cin,s);
		if (s=="DONE") break;
		string k="";
		for (int i=0;i<s.size();++i){
			if (s[i]>=65 && s[i]<=90) k+=(s[i]+32);
			else if (s[i]>=65+32 && s[i]<=90+32)k+=s[i];
		}
		(palindrome_check(k))? puts("You won't be eaten!"):puts("Uh oh..");

	}
	return 0;
}

















