#include <iostream>

using namespace std;
long long n;
long long arr[400009];
long long ans,c;
long long res[400009][2];
void siftdown (long long u);

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++) cin >> arr[i];
    for (long long i=(n+1)/2;i>=0;i--){
        siftdown(i);
    }
    cout << ans << endl;
    for (long long i=0;i<ans;i++) cout << res[i][0] << " " << res[i][1] << endl;
    return 0;
}
void siftdown (long long u){
    long long minindex=u;
    if (arr[minindex]>arr[2*minindex+1] && 2*minindex+1<n){
        minindex=2*minindex+1;
    }
    if (arr[minindex]>arr[2*minindex+2] && 2*minindex+2<n){
        minindex=2*minindex+2;
    }
    if (minindex!=u){
        c=arr[u];
        arr[u]=arr[minindex];
        arr[minindex]=c;
        res[ans][0]=u;
        res[ans][1]=minindex;
        ans++;
        siftdown(minindex);
    }
}
/*
void siftdown (long long u){
    if (arr[u]>arr[2*u+1] && 2*u+1<n){
        c=arr[u];
        arr[u]=arr[2*u+1];
        arr[2*u+1]=c;
        res[ans][0]=u;
        res[ans][1]=2*u+1;
        ans++;
        siftdown(2*u+1);
    }
    if (arr[u]>arr[2*u+2] && 2*u+2<n){
        c=arr[u];
        arr[u]=arr[2*u+2];
        arr[2*u+2]=c;
        res[ans][0]=u;
        res[ans][1]=2*u+2;
        ans++;
        siftdown(2*u+2);
    }
}
*/
