#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
long long n,m,a,b;
bool ans=1;
vector <long long> adj[100009];
int c[100009];
queue <long long> q;
void bfs(long long x);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    memset(c,-1,sizeof c);
    for (int i=0;i<n;i++) if (c[i]==-1) bfs(i);
    cout << ans << endl;
    return 0;
}
void bfs(long long x){
    c[x]=0;
    q.push(x);
    while (!q.empty()){
        long long u=q.front();
        q.pop();
        for (int i=0;i<adj[u].size();i++){
            if (c[adj[u][i]]==-1){
                c[adj[u][i]]=1-c[u];
                q.push(adj[u][i]);
            }else if (c[adj[u][i]]==c[u]){
                ans=0;
            }
        }
    }
}



