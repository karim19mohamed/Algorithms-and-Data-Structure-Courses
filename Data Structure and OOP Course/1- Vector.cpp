#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

class Vector {
private :
	int sz,cap,*arr,power[10];
public :
	Vector (){
		sz=0;
		cap=4;
		arr = new int[cap];
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
	}
	Vector (int n){
		sz=n;
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
		cap = cap_eval(sz);
		arr = new int[cap];
	}
	Vector (int n,int init_val){
		sz=n;
		power[0]=1;
		for (int i=1;i<10;++i) power[i]=power[i-1]*2;
		cap = cap_eval(sz);
		arr = new int[cap];
		initialize(init_val);
	}
	int cap_eval (int n){
		for (int i=0;i<10;++i) if (power[i]>n) return power[i];
	}
	void expand (){
		int *t=new int[cap*2];
		cap*=2;
		for (int i=0;i<sz;++i) t[i]=arr[i];
		swap(arr,t);
		delete[] t;
	}
	void schrink(){
		int *t=new int[cap/2];
		cap/=2;
		for (int i=0;i<sz;++i) t[i]=arr[i];
		swap(arr,t);
		delete[] t;
	}
	void push_input(int n){
		if (sz+1>cap) expand();
		arr[sz++]=n;
	}
	int get_val (int idx){
		return (idx>=sz || idx<0)? -999999999999 : arr[idx];
	}
	int get_size (){
		return sz;
	}
	void set_input (int idx,int n){
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
	void initialize (int n){
		for (int i=0;i<sz;++i) arr[i]=n;
	}
};

int main() {
	Vector v(100,1);
	for (int i=0;i<20;++i) v.set_input(i,i);
	v.set_input(5, 100);
	v.pop();
	v.pop();
	int ans;
	for (int i=0;i<v.get_size();++i) ans=v.get_val(i),dbg2(i,ans);
	ans=v.get_val(1000),dbg2(1000,ans);
	ans=v.get_val(-1),dbg2(-1,ans);
	return 0;
}


















