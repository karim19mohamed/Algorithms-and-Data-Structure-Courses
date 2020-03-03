#include <bits/stdc++.h>
using namespace std;
const int N = 10000, M = 40000;
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
void addBiEdge(int a, int b) {
	addEdge(a, b);
	addEdge(b, a);
}
bool vis[N];
int dfs(int i)
{
	vis[i]=1;
	int ret=1;
	for(int k=head[i];~k;k=nxt[k]){
		int j=to[k];
		if(!vis[j])
			ret+=dfs(j);
	}
	return ret;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		addBiEdge(--a, --b);
	}
	if(n-1!=ne/2 || dfs(0)!=n){
		printf("NO\n");
	}
	else
		printf("YES\n");
	return 0;
}
