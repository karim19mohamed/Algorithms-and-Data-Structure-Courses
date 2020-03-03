#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n,m,a,b;
vector <int> adj[10009][2];
stack <int> ord;
bool ves[10009][2];
int ans;
void dfs (int u,bool x);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (ves[i][1]==0) dfs(i,1);
    }
    while (!ord.empty()){
        if (ves[ord.top()][0]==0){
            dfs(ord.top(),0);
            ans++;
            //cout << "  " << ord.top() << endl;
        }
        ord.pop();
    }
    cout << ans << endl;
    return 0;
}
void dfs (int u,bool x){
    ves[u][x]=1;
    for (int i=0;i<adj[u][x].size();i++){
        if (ves[adj[u][x][i]][x]==0) dfs(adj[u][x][i],x);
    }
    if (x==1) ord.push(u);
    return;
}
