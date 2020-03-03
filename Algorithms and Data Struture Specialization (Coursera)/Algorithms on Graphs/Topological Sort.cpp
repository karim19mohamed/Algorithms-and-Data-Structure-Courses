#include <iostream>
#include <vector>
#include <stack>

using namespace std;
long long n,m,a,b;
vector <long long> adj[100009];
bool ves[100009];
stack <long long> ans;
void dfs(int u);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=1;i<=n;i++){
        if (ves[i]==0) dfs(i);
    }
    while (!ans.empty()){
        cout << ans.top();
        ans.pop();
        if (!ans.empty()) cout << " ";
    }
    cout << endl;
    return 0;
}
void dfs(int u){
    ves[u]=1;
    for (int i=0;i<adj[u].size();i++){
        if (ves[adj[u][i]]==0) dfs(adj[u][i]);
    }
    ans.push(u);
    return;
}
