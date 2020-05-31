#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
    int n,k,a[100009],num;
    bool ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;++i){
    	num=a[i];
    	int s=i,e=n-1;
    	while(s<e){
    		int mid=s+(e-s+1)/2;
    		(a[mid]<=num)? s=mid : e=mid-1;
    	}
    	//dbg2(s-i+1,num);
    	if (s-i+1>n/2){
    		ans=1;
    		break;
    	}
    }
    cout << ans << endl;
    return 0;
}









