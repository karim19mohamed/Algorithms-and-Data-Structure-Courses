#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
long long n,m,a,b,c,s,e;
vector <pair <long long,long long> > adj[1009];
priority_queue <pair <long long,long long> > q;
int dis[1009];
void dijkstra (long long x);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(c,b-1));
    }
    cin >> s >> e;
    //for (int i=0;i<1009;i++) dis[i]=1009;
    memset(dis,1,sizeof dis);
    dijkstra (s-1);
    if (dis[e-1]<10000) cout << dis[e-1] << endl;
    else cout << "-1" << endl;
    return 0;
}
void dijkstra (long long x){
    q.push(make_pair(0,x));
    dis[x]=0;
    while(!q.empty()){
        long long w=q.top().first;
        long long u=q.top().second;
        q.pop();
        if (-1*w>dis[u]) continue;
        for (int i=0;i<adj[u].size();i++){
            if ( dis[adj[u][i].second]>dis[u]+adj[u][i].first ){
                dis[adj[u][i].second]=dis[u]+adj[u][i].first;
                q.push(make_pair(-1*dis[adj[u][i].second],adj[u][i].second));
            }
        }
    }
}




