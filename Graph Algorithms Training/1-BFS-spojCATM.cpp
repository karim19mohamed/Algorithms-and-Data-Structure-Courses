#include <bits/stdc++.h>
using namespace std;
int r,c;
int distM[100*100],distC[100*100];

void bfs(int si[],int sj[],int s,int dist[100*100]){
	memset(dist,0x3f,r*c*sizeof(dist[0]));
	queue<int> q;
	for(int i=0;i<s;i++){
		int id=--si[i]*c+--sj[i];
		dist[id]=0;
		q.push(id);
	}
	while(q.size()){
		int id=q.front();
		q.pop();
		int i=id/c;
		int j=id%c;
		int di[]={0,0,1,-1};
		int dj[]={1,-1,0,0};
		for(int k=0;k<4;k++){
			int ni=i+di[k];
			int nj=j+dj[k];
			int nid=ni*c+nj;
			if(ni<0|| ni>=r || nj<0 || nj>=c || dist[nid]<=dist[id]+1)
				continue;
			dist[nid]=dist[id]+1;
			q.push(nid);
		}
	}
}
bool test(int ni,int nj){
	if(ni<0|| ni>=r || nj<0 || nj>=c)
		return false;
	int nid=ni*c+nj;
	return distM[nid]<distC[nid];
}
int main() {
	int t;
	scanf("%d%d%d",&r,&c,&t);
	while(t--){
		int mi[1],mj[1],ci[2],cj[2];
		scanf("%d%d",mi,mj);
		scanf("%d%d",ci,cj);
		scanf("%d%d",ci+1,cj+1);
		bfs(mi,mj,1,distM);
		bfs(ci,cj,2,distC);
		for(int k=0;k<max(r,c);k++)
		{
			if(test(0,k) || test(r-1,k) || test(k,0) || test(k,c-1))
			{
				printf("YES\n");
				goto nxt;
			}
		}
		printf("NO\n");
		nxt:;
	}
	return 0;
}
