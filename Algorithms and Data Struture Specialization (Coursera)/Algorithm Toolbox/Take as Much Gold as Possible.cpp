#include <iostream>
#include <cmath>

using namespace std;
long long knap;
int n;
long long w[10009];
bool flag[10009];
long long arr[309][10009];
long long ans;
long long max_knap(long long tot_w,int indx);

int main()
{
    cin >> knap >> n;
    for (int i=0;i<n;i++){
        cin >> w[i];
    }
    ans=max_knap(knap,n);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=knap;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}
long long max_knap(long long tot_w,int indx){
    if (indx<0) return 0;
    if (arr[indx][tot_w]!=0) return arr[indx][tot_w];

    //arr[indx][tot_w]=-1;
    long long wi=0;
    for (int i=0;i<n;i++){
        if(flag[i]!=1){
            flag[i]=1;
            if(w[i]<=tot_w){
                wi=max(max_knap(tot_w-w[i],indx-1)+w[i],wi);
            }
            flag[i]=0;
        }
    }
    arr[indx][tot_w]=wi;
    return wi;
}


