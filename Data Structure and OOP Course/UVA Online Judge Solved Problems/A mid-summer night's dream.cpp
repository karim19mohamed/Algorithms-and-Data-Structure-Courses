#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int main() {
	char s[10];
	while(gets(s)){
		int n,arr[1000009],a,num=0,num2=0;
		sscanf(s,"%d",&n);
		for (int i=0;i<n;++i) scanf("%d",&arr[i]);
		sort(arr,arr+n);
		if (n%2){
			a=arr[n/2];
			for (int i=0;i<n;++i) if (arr[i]==a) ++num;
			num2=1;
		}else{
			a=min(arr[n/2],arr[(n/2)-1]);
			for (int i=0;i<n;++i) if (arr[i]==arr[n/2] || arr[i]==arr[(n/2)-1]) ++num;
			num2=arr[n/2]-arr[(n/2)-1]+1;
		}

		printf("%d %d %d\n",a,num,num2);
		gets(s);
	}
	return 0;
}


































