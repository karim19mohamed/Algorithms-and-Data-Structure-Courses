#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;


int main() {
    int n,k,a[100009],num;
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    scanf("%d",&k);
    while(k--){
    	scanf("%d",&num);
    	int s=0,e=n-1;
    	while(s<e){
    		int mid=s+(e-s+1)/2;
    		(a[mid]<=num)? s=mid : e=mid-1;
    	}
    	//dbg3(num,a[s],s);
    	(a[s]==num)? cout<<s : cout<<"-1";
    	cout<< " \n"[k==0];
    }
    return 0;
}









