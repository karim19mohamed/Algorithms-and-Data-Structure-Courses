#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
vector <int> arr[1009];
queue <int> q;
bool vis[1009];
int f,e;
bool ans=0;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int k,u;
        cin >> k >> u;
        arr[k].push_back(u);
        arr[u].push_back(k);
    }
    cin >> f >> e;
    q.push(f);
    while (!q.empty()){
        int sz=q.size();
        for (int i=0;i<sz;i++){
            if (q.front()==e){
                ans=1;
                break;
            }
            int sz2=arr[q.front()].size();
            for (int i=0;i<sz2;i++){
                if (vis[arr[q.front()][i]]==1) continue;
                q.push(arr[q.front()][i]);
                vis[arr[q.front()][i]]=1;
            }
            q.pop();
        }
        if (ans==1) break;
    }
    cout << ans << endl;
    return 0;
}
/*
4 4
1 2
3 2
4 3
1 4
1 4
*/
