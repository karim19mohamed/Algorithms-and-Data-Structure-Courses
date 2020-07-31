#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	char s[100009];
	queue <pair<char,int> > q;
	while(gets(s)){
		list <char> mylist1;
		int len = strlen (s);
		bool direction=0;
		for (int i=0;i<len;++i){
			if (s[i]=='['){
				q.push({s[i],i});
				direction=1;
				continue;
			}else if (s[i]==']'){
				q.push({s[i],i});
				direction=0;
				continue;
			}
			if (!direction) mylist1.push_back(s[i]);
		}
		while(!q.empty()){
			char c=q.front().first;
			int idx1=q.front().second;
			q.pop();
			if (c==']') continue;
			int idx2=(!q.empty())? q.front().second : len;
			for (int i=idx2-1;i>=idx1+1;--i){
				mylist1.push_front(s[i]);
			}
		}
		std::list<char>::iterator it;
		for (it=mylist1.begin(); it!=mylist1.end(); ++it){
			printf("%c",*it);
		}
		printf("\n");
	}
	return 0;
}
