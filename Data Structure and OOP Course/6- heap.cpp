#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

template<class T>
class heap{
	vector<T> tree;
	void heapUP(int i){
		while(i){
			int parent=(i-1)/2;
			if(tree[i]>tree[parent]){
				swap(tree[i],tree[parent]);
				i=parent;
			}else break;
		}
	}
	void heapDown(int i){
		while(2*i+1<tree.size()){
			int left=2*i+1,right=2*i+2;
			int mx=(right<tree.size())? ((tree[right]>tree[left])? right : left ): left;
			if (tree[mx]>tree[i]){
				swap(tree[i],tree[mx]);
				i=mx;
			}else break;
		}
	}
public:
	void add(T n){
		tree.push_back(n);
		heapUP(tree.size()-1);
	}
	T getMax(){
		return tree[0];
	}
	void removeMax(){
		swap(tree[0],tree.back());
		tree.pop_back();
		heapDown(0);
	}
	bool empty(){
		return tree.size()==0;
	}
	void print(int i=0,int d=0){
		if(i>=tree.size()) return;
		T dig=tree[i];
		int num=0;
		while(dig) ++num,dig/=10;
		print(2*i+1,d+num+1);
		cout << string(d,' ') << tree[i] << endl;
		print(2*i+2,d+num+1);
	}
};

int main() {
	int arr[]={13,2,53,0,9,199,7,1,5,1,20,4,1,7,3,4};
	heap<int> q;
	for (auto &i:arr) q.add(i);
	while (!q.empty()){
		q.print();
		int m=q.getMax();
		dbg(m);
		q.removeMax();
		puts("-----------------------");
	}

	return 0;
}
















