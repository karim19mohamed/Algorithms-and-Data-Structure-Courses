#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

void spaces (int n){
	for (int i=0;i<n;++i) printf(" ");
}
int num_spaces (int n){
	if (n==0) return 3;
	int ans;
	if (n/10==0) ans=3;
	else if (n/100==0) ans=2;
	else if (n/1000==0) ans=1;
	else ans=0;
	return (n>0)? ans : ans-1;
}


int main() {
	int t,g;
	priority_queue <pair<pair<pair<int,int >,int >,int> > q;
	bool f=0;
	while(cin>>t>>g && t){
		if(f) printf("\n");
		f=1;
		map <string,int> m;
		map <int,string> m_back;
		map <string,string> m_to_uppercase;
		vector <int> v[300];  // index m[team_name] --> goal,suffered,num_games,points
		queue <string> team;
		priority_queue <string> arranged_team;
		string s,s_uppercase;
		for (int i=0;i<t;++i){
			cin>>s;
			s_uppercase=s;
			for (int j=0;j<s_uppercase.size();++j) if(s_uppercase[j]>90) s_uppercase[j]=s_uppercase[j]-32;
			team.push(s_uppercase);
			arranged_team.push(s_uppercase);
			m_to_uppercase[s_uppercase]=s;
		}
		int idx=0;
		while(!arranged_team.empty()){
			m[arranged_team.top()]=idx;
			m_back[idx]=arranged_team.top();
		    ++idx;
			for (int j=0;j<4;++j) v[m[arranged_team.top()]].push_back(0);
			arranged_team.pop();
		}
		//dbg("end teams");
		string t1,rabbish,t2;
		int g1,g2;
		for (int i=0;i<g;++i){
			cin>>t1>>g1>>rabbish>>g2>>t2;
			for (int j=0;j<(int)t1.size();++j) if(t1[j]>90) t1[j]=t1[j]-32;
			for (int j=0;j<(int)t2.size();++j) if(t2[j]>90) t2[j]=t2[j]-32;
			//cout << t1<<" "<<g1<<" "<<rabbish<<" "<<g2<<" "<<t2<<" "<< endl;
			v[m[t1]][0]+=g1; v[m[t2]][0]+=g2;
			v[m[t1]][1]+=g2;  v[m[t2]][1]+=g1;
			++v[m[t1]][2];   ++v[m[t2]][2];
			if (g1>g2) v[m[t1]][3]+=3;
			else if (g2>g1) v[m[t2]][3]+=3;
			else ++v[m[t1]][3],++v[m[t2]][3];
		}
		//dbg("end game");
		while(!team.empty()){
			string tmp=team.front();
			team.pop();
			int points=v[m[tmp]][3],goal_diff=v[m[tmp]][0]-v[m[tmp]][1], scored_goal=v[m[tmp]][0];
			//reverse(tmp.begin(),tmp.end());
			//q.push( { { { points,goal_diff },scored_goal },m[tmp] } );
			q.push(make_pair(make_pair(make_pair(points,goal_diff),scored_goal), m[tmp]));
		}
		//dbg("end queue");
		int clas=1;
		bool new_clas=1;
		while(!q.empty()){
			int    points=q.top().first.first.first,
				   goal_diff=q.top().first.first.second,
				   scored_goal=q.top().first.second,
				   num_tmp=q.top().second;
			string tmp=m_back[num_tmp];
			//reverse(tmp.begin(),tmp.end());
			int    num_game=v[m[tmp]][2],
				   suffer_goal=v[m[tmp]][1];
			double percent=(num_game>0)? (points*100.0)/(num_game*3.0) : -1.0;
			tmp=m_to_uppercase[tmp];
			q.pop();
			if(new_clas){
				(clas/10)?printf("%d. ",clas) : printf(" %d. ",clas);
				new_clas=0;
			}else{
				printf("    ");
			}
			for (int i=0;i<15-tmp.size();++i) printf(" ");
			cout << tmp;
			spaces(num_spaces(points));      printf("%d",points);
			spaces(num_spaces(num_game));    printf("%d",num_game);
			spaces(num_spaces(scored_goal)); printf("%d",scored_goal);
			spaces(num_spaces(suffer_goal)); printf("%d",suffer_goal);
			spaces(num_spaces(goal_diff));   printf("%d",goal_diff);
			if (percent!=-1){
				spaces(num_spaces(percent)); printf("%.2lf\n",percent);
			}else{
				spaces(num_spaces(1)); printf(" N/A\n");
			}
			int    points2=q.top().first.first.first,
				   goal_diff2=q.top().first.first.second,
				   scored_goal2=q.top().first.second;
			if (points2<points || goal_diff2<goal_diff || scored_goal2<scored_goal){
				new_clas=1;
			}
			++clas;
		}
	}
	return 0;
}
