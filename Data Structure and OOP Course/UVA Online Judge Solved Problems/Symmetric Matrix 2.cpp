#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

class Vector {
private :
	int sz,cap,power[10];
	ll *arr;
public :
	Vector (){
		sz=0;
		cap=4;
		arr = new ll[cap];
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
	}
	Vector (int n){
		sz=n;
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
		cap = cap_eval(sz);
		arr = new ll[cap];
	}
	Vector (int n,ll init_val){
		sz=n;
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
		cap = cap_eval(sz);
		arr = new ll[cap];
		initialize(init_val);
	}
	int cap_eval (int n){
		for (int i=0;i<10;++i) if (power[i]>n) return power[i];
	}
	void expand (){
		ll *t=new ll[cap*2];
		cap*=2;
		for (int i=0;i<sz;++i) t[i]=arr[i];
		swap(arr,t);
		delete[] t;
	}
	void schrink(){
		ll *t=new ll[cap/2];
		cap/=2;
		for (int i=0;i<sz;++i) t[i]=arr[i];
		swap(arr,t);
		delete[] t;
	}
	void push_input(ll n){
		if (sz+1>cap) expand();
		arr[sz++]=n;
	}
	int get_val (int idx){
		return (idx>=sz || idx<0)? -999999999999 : arr[idx];
	}
	int get_size (){
		return sz;
	}
	void set_input (int idx,ll n){
		(idx>=sz || idx<0)? puts("out of boundary"):arr[idx]=n;
	}
	void pop(){
		if (sz-1<0){
			puts("out of boundary");
		}else{
			if (sz-1<cap/4){
				--sz;
				schrink();
			}else{
				--sz;
			}
		}
	}
	void initialize (ll n){
		for (int i=0;i<sz;++i) arr[i]=n;
	}
};

int main() {
	int t,n,cs=1;
	ll a;
	char c;
	scanf("%d",&t);
	while (t--){
		bool ans=1;
		for (int i=0;i<4;++i) scanf("%c",&c);
		scanf("%d",&n);
		Vector v[n];
		for (int i=0;i<n;++i) for (int j=0;j<n;++j){
			scanf("%lld",&a);
			v[i].push_input(a);
			if (a<0) ans=0;
		}
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j){
				if ( v[i].get_val(j)!=v[n-1-i].get_val(n-1-j) ){
					ans=0;
					break;
				}
			}
			if (!ans) break;
		}
		(ans) ? printf("Test #%d: Symmetric.\n",cs++) : printf("Test #%d: Non-symmetric.\n",cs++);
	}

	return 0;
}


















