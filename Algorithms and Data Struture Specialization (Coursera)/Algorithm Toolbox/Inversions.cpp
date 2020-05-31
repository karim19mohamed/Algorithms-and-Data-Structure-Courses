#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
    int n,a[100009],b[100009];
    int ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
    	scanf("%d",&a[i]);
    	b[i]=a[i];
    }
    sort(b,b+n);
    for (int i=0;i<n;++i){
    	if (a[i]!=b[i]) ++ans;
    }
    (ans)? cout << ans-1 << endl : cout << "0" << endl;
    return 0;
}









