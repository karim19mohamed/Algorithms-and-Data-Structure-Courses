#include <iostream>
#include <cmath>

using namespace std;
long long n;
long long arr[10000000];
long long x[10000000];
long long k[10000000];
long long ans;

int main()
{
    cin >> n;
    if (n==1) {
        ans=arr[1];
    }else{
        for (long long i=2;i<=n;i++){
            arr[i]=10000000;
            if (i%2==0) {
                ans=min(arr[i/2]+1,arr[i]);
                if (arr[i/2]+1<arr[i]) k[i]=i/2;
                arr[i]=ans;
            }
            if (i%3==0) {
                ans=min(arr[i/3]+1,arr[i]);
                if (arr[i/3]+1<arr[i]) k[i]=i/3;
                arr[i]=ans;
            }
            if (i-1>=0){
                ans=min(arr[i-1]+1,arr[i]);
                if (arr[i-1]+1<arr[i]) k[i]=i-1;
                arr[i]=ans;
            }
            //cout << arr[i] << "   " << i << "   " << k[i] << endl;
        }
    }
    cout << ans << endl;
    for (int i=ans;i>=0;i--){
        x[i]=n;
        n=k[n];
        //cout << "   " << x[i] << endl;
    }
    for (int i=0;i<=ans;i++){
        cout << x[i];
        if (i!=ans) cout << " ";
    }
    cout << endl;
    return 0;
}
