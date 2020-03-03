#include <iostream>
#include <algorithm>

using namespace std;
int n;

int main()
{
    cin >> n;
    long long a[n];
    long long b[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    long long ans=0;
    for (int i=0;i<n;i++){
        //cout << a[i] << "   " << b[i] << "   " << a[i]*b[i] << endl;
        ans+=a[i]*b[i];
    }
    cout << ans << endl;
    return 0;
}
