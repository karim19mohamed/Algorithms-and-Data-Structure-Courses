#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

double p,q,r,s,t,u;
double valid(double x){
	//p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x^2+u=0
	double eq=(p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u;
	return eq;
}

int main() {
	while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
		double st=0,et=1;
		bool ans=(valid(st)*valid(et)>0);
		for(double mid=(et-st)/2;mid>=1e-8;mid*=0.5){
			if (valid(st+mid)>=0){
				st+=mid;
			}
		}
		(!ans)? printf("%.4lf\n",st) :puts("No solution") ;
	}
	return 0;
}


















