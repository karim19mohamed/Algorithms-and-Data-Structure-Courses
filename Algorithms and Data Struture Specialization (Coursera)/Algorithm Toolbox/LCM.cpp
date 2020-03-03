#include <iostream>
#include <cmath>

using namespace std;
long long a;
long long b;
long long ans;

int main()
{
    cin >> a >> b;
    if (a==0 || b==0) ans=max(a,b);
    long long m=max(a,b);
    long long n=min(a,b);
    //cout << m << "   " << n << endl;
    while (m!=0 && n!=0){
        if (n) ans=n;
        long long k=m/n;
        k=m-(k*n);
        m=n;
        n=k;
    }
    a=a/ans;
    ans=a*b;
    cout << ans << endl;
    return 0;
}
