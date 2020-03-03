#include <iostream>

using namespace std;
int n;
int tot_w;
int v[1005];
int w[1005];
bool flag[1005];
void loot(int idx,int sum,int weight);

int main()
{
    cin >> n >> tot_w;
    for (int i=0;i<n;i++){
        cin >> v[i] >> w[i];
    }
    loot (0,0,0);


    return 0;
}
void loot(int idx,int sum,int weight){
    if (weight==tot_w){
        cout << sum << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if (flag[i]==1){
            flag[i]=1;
            if (tot_w%w[i] >0){
                loot (idx+1,sum+v[i],weight+w[i]);
            }else{
                loot (idx+1,sum+v[i]*tot_w/w[i],weight+w[i]);
            }
            flag[i]=0;
        }
    }
}
