#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector <int> adj[1009];
bool ves[1009];
bool ans;
void dfs(int u,int in);
int a,b;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) ves[j]=0;
        dfs(i,i);
        if (ans==1) break;
    }
    cout << ans << endl;
    return 0;
}
void dfs(int u,int in){
    ves[u]=1;
    for (int i=0;i<adj[u].size();i++){
        if (adj[u][i]==in){
            ans=1;
            break;
        }else{
            if (ves[adj[u][i]]!=1) dfs(adj[u][i],in);
        }
    }
    return;
}
/*
4 4
1 2
4 1
2 3
3 1
*/
