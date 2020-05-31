// CodeForces Three Base Stations
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int n,a[200009];
bool double_compare(int a,double b){
	// fair comparison without subtracting any digit from b
	double tmp=(b+(1e-7))*1000000.0;
	ll tmp2=tmp,tmp3=(ll)a*1000000;
	return tmp3>tmp2;
}
bool valid(double d){
	double pos=(double)(a[0])+d;
	int num=1;
	for (int i=1;i<n;++i){
		double tmp=(pos+d)*1000000.0;
		ll tmp2=tmp,tmp3=(ll)a[i]*1000000;
		if(tmp3>tmp2){
			++num;
			pos=(double)(a[i])+d;
		}
	}
	return num<=3;
}
void print_pos(double d){
	double pos=(double)(a[0])+d;
	printf("%.6lf",pos);
	int num=1;
	for (int i=1;i<n;++i){
		if(double_compare(a[i],pos+d)){
			++num;
			pos=(double)(a[i])+d;
			printf(" %.6lf",pos);
		}
	}
	while(num<3) ++num,printf(" %.6lf",pos);
	printf("\n");
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	double s=0,e=2e10;

	// using FFFFFTTTT in binary search to be TTTTTFFFF
	// be careful about the last true of the first that became false in the second
	for(double mid=(e-s)/2;mid>=1e-8;mid*=0.5){
		if(!valid(s+mid)) s+=mid;
	}
	printf("%.6lf\n",s);
	print_pos(s);
	return 0;
}


















