#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int p,c,cs=1;
	char ch;
	while (cin>>p>>c && p){
		list <pair<int,int> > q;
		map <int,int> cnt;
		printf("Case %d:\n",cs++);
		for(int i=1;i<=min(p,c+1);++i) q.push_back({i,0});
		for (int i=0;i<c;++i){
    		scanf(" %c",&ch);
    		int a,num;
    		if(ch=='N'){
    			while (cnt[q.front().first]>q.front().second) q.pop_front();
    			a=q.front().first;
    			num=q.front().second;
    			q.pop_front();
    			q.push_back({a,num+1});
    			cnt[a]=num+1;
    			printf("%d\n",a);
    		}else{
    			scanf("%d",&a);
    			q.push_front({a,cnt[a]+1});
    		}
		}
	}
	return 0;
}


















