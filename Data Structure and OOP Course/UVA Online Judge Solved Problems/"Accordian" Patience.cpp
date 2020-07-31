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
		stack <string> pile[52];
		pile[0].push(s);
		for (int i=1;i<52;++i){
			cin>>s;
			pile[i].push(s);
		}
		bool change=1;
		while (change){
			change=0;
			for (int i=0;i<52;++i){
				if (pile[i].empty()) break;
				string s1=pile[i].top();
				if (i+1<52 && !pile[i+1].empty() && (s1[0]==pile[i+1].top()[0] || s1[1]==pile[i+1].top()[1])){
					pile[i].push(pile[i+1].top());
					pile[i+1].pop();
					int idx=i+1;
					if (pile[i+1].empty()) while (idx<51) swap(pile[idx],pile[idx+1]),++idx;
					change=1;
					break;
				}else if (i+3<52 && !pile[i+3].empty() && (s1[0]==pile[i+3].top()[0] || s1[1]==pile[i+3].top()[1])){
					if (i+1<52 && i+2<52 && !pile[i+1].empty() && !pile[i+2].empty()){
						if (pile[i+1].top()[0]==pile[i+2].top()[0] || pile[i+1].top()[1]==pile[i+2].top()[1])
							continue;
					}
					pile[i].push(pile[i+3].top());
					pile[i+3].pop();
					int idx=i+3;
					if (pile[i+3].empty()) while (idx<51) swap(pile[idx],pile[idx+1]),++idx;
					change=1;
					break;
				}
			}
		}
		//dbg2(pile[0].top(),pile[1].top());
		int piles_cnt=0,pile_size=0;
		for (int i=0;i<52;++i){
			if (!pile[i].empty()) ++piles_cnt;
			else break;
		}
		(piles_cnt==1)? printf("%d pile remaining:",piles_cnt): printf("%d piles remaining:",piles_cnt);
		for (int i=0;i<piles_cnt;++i){
			pile_size=pile[i].size();
			printf(" %d",pile_size);
			while (!pile[i].empty()) pile[i].pop();
		}
		printf("\n");
	}
	return 0;
}


































