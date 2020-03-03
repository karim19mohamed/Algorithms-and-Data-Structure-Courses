/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 128, M = 10000 * 2;
int head[N], nxt[M], to[M], cost[M], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t, int c) {
	nxt[ne] = head[f];
	to[ne] = t;
	cost[ne] = c;
	head[f] = ne++;
}
void addBiEdge(int a, int b, int c) {
	addEdge(a, b, c);
	addEdge(b, a, c);
}

int dist[N];
int n=128;


void dij(int src)
{
	memset(dist,0x3f,n*sizeof dist[0]);
	dist[src]=0;
	priority_queue<pair<int,int> > q;
//	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

	q.push({0,src});
	while(q.size())
	{
		int d=-q.top().first;
		int i=q.top().second;
		q.pop();
		if(dist[i]!=d)continue;
		for(int k=head[i];~k;k=nxt[k]){
			int j=to[k];
			int dj=d+cost[k];
			if(dist[j]>dj){
				dist[j]=dj;
				q.push({-dj,j});
			}
		}
	}
}

int main() {
	freopen("comehome.in", "rt", stdin);
	freopen("comehome.out", "wt", stdout);
	int m;
	scanf("%d",&m);
	init(n);
	while(m--)
	{
		char a,b;
		int c;
		scanf(" %c %c%d",&a,&b,&c);
		addBiEdge(a, b, c);
	}
	dij('Z');
	char sol=min_element(dist+'A', dist+'Z')-dist;
	printf("%c %d\n",sol,dist[sol]);
	return 0;
}
