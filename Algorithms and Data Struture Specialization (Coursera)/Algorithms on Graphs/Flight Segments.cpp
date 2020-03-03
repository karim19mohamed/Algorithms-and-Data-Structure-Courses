#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
long long n,m,a,b,s,e;
vector <long long> adj[100009];
long long dis[100009];
queue <long long> q;
void bfs(long long x);

int main()
{
    cin >> n >> m;
    for (long long i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s >> e;
    memset(dis,-1,sizeof dis);
    bfs(s);
    cout << dis[e] << endl;
    return 0;
}
void bfs(long long x){
    dis[x]=0;
    q.push(x);
    while (!q.empty()){
        long long u=q.front();
        q.pop();
        for (long long i=0;i<adj[u].size();i++){
            if (dis[adj[u][i]]==-1){
                q.push(adj[u][i]);
                dis[adj[u][i]]=dis[u]+1;
            }
        }
    }
}


