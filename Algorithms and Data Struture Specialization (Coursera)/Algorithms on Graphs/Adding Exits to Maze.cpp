#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
vector <int> arr[1009];
queue <int> q;
bool vis[1009];
int ans=0;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int k,u;
        cin >> k >> u;
        arr[k].push_back(u);
        arr[u].push_back(k);
    }
    for (int j=1;j<=n;j++){
        if (vis[j]==1) continue;
        q.push(j);
        ans++;
        while (!q.empty()){
            int sz=q.size();
            for (int i=0;i<sz;i++){
                int sz2=arr[q.front()].size();
                for (int i=0;i<sz2;i++){
                    if (vis[arr[q.front()][i]]==1) continue;
                    q.push(arr[q.front()][i]);
                    vis[arr[q.front()][i]]=1;
                }
                q.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
