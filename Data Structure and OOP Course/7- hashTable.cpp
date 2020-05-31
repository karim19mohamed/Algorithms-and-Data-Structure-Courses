#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

unsigned int HASH(int x){
	return x;
}
template<class T>
class hashTable{
	enum state{Empty,Full,Del};
	vector<T> data;
	vector<state> st;
	int size;
	int find_idx_to_save(T &val,vector<T> &d,vector<state> &s){
		int i=HASH(val)%d.size();
		while (s[i]==Full && d[i]!=val) ++i%=d.size();
		return i;
	}
	int find_idx_if_contain(T &val,vector<T> &d,vector<state> &s){
		int i=HASH(val)%d.size();
		while (s[i]!=Empty && d[i]!=val) ++i%=d.size();
		return i;
	}
	void add(T &val,vector<T> &d,vector<state> &s){
		int idx=find_idx_to_save(val,d,s);
		d[idx]=val,s[idx]=Full;
	}
	void rehash(){
		if (size*2>data.size()){
			vector<T> d(size*4);
			vector<state> s(size*4);
			for(int i=0;i<st.size();++i){
				if (st[i]==Full) add(data[i],d,s);
			}
			swap(data,d);
			swap(st,s);
		}
	}
public:
	hashTable (): size(0),data(1),st(1){}
	void add(T n){
		++size;
		rehash();
		add(n,data,st);
	}
	void erase(T n){
		int i=find_idx_if_contain(n,data,st);
		if (st[i]==Full) st[i]=Del,--size;
	}
	bool contain(T n){
		int i=find_idx_if_contain(n,data,st);
		dbg(i);
		return st[i]==Full;
	}
	void print(){
		cout << "Size : " << size << endl;
		for (int i=0;i<st.size();++i){
			switch (st[i]){
				case Full:
					cout<<data[i];
					break;
				case Empty:
					printf("E");
					break;
				case Del:
					printf("D");
					break;
			}
			cout<<" \n"[i==st.size()-1];
		}
	}
};

int main() {
	int arr[] = {3, 5, 9, 2, 7, 14};
	hashTable<int> h;
	for (int i = 0; i < 5; ++i) {
		h.add(arr[i]);
		h.print();
	}
	h.erase(3);
	h.print();
	h.add(14);
	h.print();
	cout<<h.contain(5)<<" "<<h.contain(14)<<endl;

	return 0;
}
















