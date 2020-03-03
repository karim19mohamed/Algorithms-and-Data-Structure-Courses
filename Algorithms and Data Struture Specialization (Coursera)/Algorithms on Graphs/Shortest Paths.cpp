#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int n,m,a,b,s;
long long c;
vector <pair <long long,int> > adj[1009];
queue <int> q;
long long dis[1009];
bool reach[1009];
bool neg[1009];
void bellman (int u,int q);
void dfs (int u);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(c,b-1));
    }
    cin >> s;
    for (int i=0;i<n;i++){
        dis[i]=1000000000000000;
    }
    bellman (s-1,n);
    bellman (s-1,2);
    dfs(s-1);

    for (int i=0;i<n;i++){
        if (reach[i]==0) cout << "*" << endl;
        else if (neg[i]==1) cout << "-" <<endl;
        else cout << dis[i] << endl;
    }
    return 0;
}
void bellman (int u,int q){
    if (q!=2) dis[u]=0;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<adj[j].size();k++){
                if (dis[ adj[j][k].second ]>dis[j]+adj[j][k].first){
                    dis[ adj[j][k].second ]=dis[j]+adj[j][k].first;
                    if (q==2){
                        neg[adj[j][k].second]=1;
                    }
                }
            }
        }
    }
}
void dfs (int u){
    reach[u]=1;
    for (int i=0;i<adj[u].size();i++){
        if (reach[adj[u][i].second]==0){
            dfs(adj[u][i].second);
        }
    }
    return;
}





