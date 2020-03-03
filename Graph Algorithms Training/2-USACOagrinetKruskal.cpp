/*
 TASK: agrinet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = N * N;

int par[N], setSize[N], numOfSets;

void init(int n) {
	numOfSets=n;
	while(n--)
		setSize[n]=1,par[n]=n;
}

int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}
void join(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(setSize[b]<setSize[a])
		swap(a,b);
	par[a]=b;
	setSize[b]+=setSize[a];
	numOfSets--;
}

int ne = 0;
struct edge {
	int f, t, c;
	bool operator<(const edge &e)const{
		return c<e.c;
	}
} edges[M];

void addEdge(int f, int t, int c) {
	edges[ne++]= {f,t,c};
}

int kruskal() {
	int sol = 0;
	sort(edges,edges+ne);
	for(int i=0;i<ne && numOfSets>1;i++)
		if(find(edges[i].f)!=find(edges[i].t))
			join(edges[i].f,edges[i].t),sol+=edges[i].c;
	return sol;
}
int main() {
	freopen("agrinet.in", "rt", stdin);
	freopen("agrinet.out", "wt", stdout);
	int n;
	scanf("%d", &n);
	init(n);
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++) {
			int c;
			scanf("%d", &c);
			addEdge(a, b, c);
		}
	int sol = kruskal();
	printf("%d\n", sol);
	return 0;
}
