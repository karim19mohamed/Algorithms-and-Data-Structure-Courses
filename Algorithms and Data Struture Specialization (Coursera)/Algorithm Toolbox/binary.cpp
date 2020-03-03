#include <iostream>
#include <cmath>

using namespace std;
int n;
int k;
long long a[100000];
long long b[100000];
int exist(int i,int indx,long long x);

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        //cout << a[10] << endl;
    }
    cin >> k;
    for (int i=0;i<k;i++){
        cin >> b[i];
    }
    for (int j=0;j<k;j++){
        int ans = exist(n/2,n/2,b[j]);
        cout << ans;
        cout << " ";
    }
    return 0;
}
int exist(int i,int indx,long long x){
    //cout << "i=" <<i << "   indx="<<indx << "   a="<<a[i] << "   x="<<x <<endl;
    if (a[i]==x) return i;
    if (indx==0) return -1;
    //int asas;
    //cin >> asas;
    if (a[i]>x){
        exist(i-ceil((float)(indx+1)/2),indx/2,x);
    }else{
        exist(i+ceil((float)(indx)/2),indx/2,x);
    }

}



