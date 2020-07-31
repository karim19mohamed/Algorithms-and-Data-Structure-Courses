#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	int t,stations,carrier,b;
	scanf("%d",&t);
	queue <int> q[109];
	stack <int> s;
	while(t--){
		scanf("%d %d %d",&stations,&carrier,&b);
		int tot_cargo=0;
		for (int i=0;i<stations;++i){
			int tmp,cargo;
			scanf("%d",&tmp);
			for (int j=0;j<tmp;++j){
				scanf("%d",&cargo);
				q[i].push(cargo-1);
				tot_cargo++;
			}
		}
		//dbg(tot_cargo);
		bool empty_b=0;
		int ans=0;
		while (tot_cargo){
			empty_b=1;
			for (int i=0;i<stations;++i){
				if (i!=0 && tot_cargo) ans+=2;
				while (!s.empty() && ( s.top()==i ||q[i].size()<b)){
					if (s.top()==i) --tot_cargo;
					else q[i].push(s.top());
					s.pop();
					++ans;
				}
				while (!q[i].empty() && s.size()<carrier){
					s.push(q[i].front()) , q[i].pop() , ++ans;
				}
				if (!q[i].empty()) empty_b=0;
			}
			if (tot_cargo) ans+=2;
		}
		printf("%d\n",ans);

	}
	return 0;
}




















