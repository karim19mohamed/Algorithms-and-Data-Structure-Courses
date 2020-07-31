#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int test;
queue <string> q;
string a,b;
void stack_orders(stack<char> s,string ans,int idx_a,int idx_b ){
	if (idx_a==a.size() && idx_b==b.size()){
		//cout << ans << endl;
		q.push(ans);
		return;
	}
	if (idx_a==a.size() && !s.empty()) if (s.top()!=b[idx_b]) return;

	//cout << ans << endl;//cin>> test;
	s.push(a[idx_a]);
	if (idx_a<a.size()) stack_orders(s,ans+"i ",idx_a+1,idx_b);
	s.pop();
	if (!s.empty() && s.top()==b[idx_b]){
		s.pop();
		if (idx_b<b.size()){
			(idx_b<b.size()-1)? stack_orders(s,ans+"o ",idx_a,idx_b+1):stack_orders(s,ans+"o",idx_a,idx_b+1);
		}
	}
}

int main() {

	while(cin>>a>>b){
		if (a.size()!=b.size()){
			printf("[\n]\n");
			continue;
		}
		stack<char> s;
		stack_orders(s,"",0,0);
		printf("[\n");
		while(!q.empty()){
			cout << q.front() << endl;
			q.pop();
		}
		printf("]\n");
	}
	return 0;
}




















