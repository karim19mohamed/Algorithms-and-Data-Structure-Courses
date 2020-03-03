#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n,m,a,b,c;
vector <pair<int,int> > adj[1009];
long long dis[1009];
bool ans;
void bellman (int u,int q);

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(c,b-1));
    }
    for (int i=0;i<n;i++) dis[i]=100000000;
    bellman (0,n);
    bellman (0,2);
    cout << ans << endl;
    return 0;
}
void bellman (int u,int q){
    dis[u]=0;
    for (int i=0;i<q-1;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<(int)adj[j].size();k++){
                if (dis[ adj[j][k].second ] > dis[j]+adj[j][k].first){
                    dis[ adj[j][k].second ] = dis[j]+adj[j][k].first;
                    if (q==2) {
                        ans=1;
                        cout << "sdas" << endl;
                    }
                }
            }
        }
    }
}



