

/*
 TASK: agrinet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 200;
int head[N], nxt[M], to[M], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
int n;
unordered_map<string, int> mp;
vector<string> names;
int get(const string&s) {
	return mp.insert( { s, mp.size() }).first->second;
}
int vis[N],vid;

int res[N],resSz;
void dfs(int i)
{
	vis[i]=vid;
	for(int k=head[i];~k;k=nxt[k]){
		int j=to[k];
		if(vid!=vis[j])
			dfs(j);
	}
	res[resSz++]=i;
}
void topo(){
	vid++;
	resSz=0;
	for(int i=0;i<n;i++)
		if(vis[i]!=vid)
			dfs(i);
	reverse(res,res+n);
}
int main() {
	freopen("agrinet.in", "rt", stdin);
	int tc=1;
	while (~scanf("%d", &n)) {
		init(n);
		mp.clear();
		names.clear();
		for (int i = 0; i < n; i++) {
			char arr[52];
			scanf("%s", arr);
			names.push_back(arr);
			get(arr);
		}
		int m;
		scanf("%d", &m);
		while (m--) {
			char arr[52];
			scanf("%s", arr);
			int f=get(arr);
			scanf("%s", arr);
			int t=get(arr);
			addEdge(f, t);
		}
		topo();
		printf("Case #%d: Dilbert should drink beverages in this order:",tc++);
		for(int i=0;i<n;i++)
			printf(" %s",names[res[i]].c_str());
		puts(".");
		puts("");
	}
	return 0;
}
