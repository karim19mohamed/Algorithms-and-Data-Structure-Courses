#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;



void merege(int s,int mid,int e,vector<int> &v){
	vector <int> c;
	int st=s,ed=e,mid_pt=mid+1;
	while(st<=mid && mid_pt<=ed) (v[st]<v[mid_pt])? c.push_back(v[st++]) : c.push_back(v[mid_pt++]);
	while(st<=mid) c.push_back(v[st++]);
	for (int i=s;i<=(int)c.size()+s;++i) v[i]=c[i-s];
}

void merge_sort(int s,int e,vector<int> &v){
	if (e-s==0) return;
	if (e-s==1){
		if (v[s]>v[e]) swap(v[s],v[e]);
		return;
	}
	int mid=s+((e-s)/2);
	merge_sort(s,mid,v);
	merge_sort(mid+1,e,v);
	merege(s,mid,e,v);
}

int main() {
	int n;
	while(cin>>n && n){
		int a;
		vector <int> v;
		for (int i=0;i<n;++i){
			scanf("%d",&a);
			v.push_back(a);
		}
		merge_sort(0,n-1,v);
		for (int i=0;i<n;++i){
			printf("%d ",v[i]);
		}
		printf("\n");
	}
	return 0;
}


















