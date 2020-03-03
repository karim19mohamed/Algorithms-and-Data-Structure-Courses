#include <iostream>

using namespace std;
int n;
double long tot_w;

int main()
{
    cin >> n >> tot_w ;
    double long v[n];
    double long w[n];
    for (int i=0;i<n;i++){
        cin >> v[i] >> w[i] ;
        //cout << "efsdf" << endl;
    }
    double long ans=0;
    while (tot_w!=0){
        int max_ind=0;
        double long max_value=0;
        int indi=0;
        for (int i=0;i<n;i++){
            if (w[i]==0) continue;
            if (w[i]<=tot_w){
                if (max_value<v[i]){
                    max_value=v[i];
                    max_ind=i;
                    indi=0;
                }
                if (max_value==v[i]){
                    if (w[max_ind]>w[i]){
                        max_value=v[i];
                        max_ind=i;
                        indi=0;
                    }
                }
            }else{
                if (max_value<v[i]*( tot_w / w[i] ) ){
                    max_value=v[i]*( tot_w / w[i] );
                    max_ind=i;
                    indi=1;
                }
                if (max_value==v[i]*( tot_w / w[i] ) ){
                    if (w[max_ind]>w[i]){
                        max_value=v[i]*( tot_w / w[i]);
                        max_ind=i;
                        indi=1;
                    }
                }
            }
        }
        if (w[max_ind]==0) break;
        ans+=max_value;
        if (indi==0){
            tot_w-=w[max_ind];
            w[max_ind]=0;
        }else{
            tot_w=0;
            w[max_ind]-=tot_w;
        }
    }
    cout << ans << endl;
    return 0;
}
