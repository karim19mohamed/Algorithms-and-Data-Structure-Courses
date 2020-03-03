/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 128, M = 10000 * 2;
int cost[N][N];
void init(int n) {
	memset(cost, 0x3f, sizeof cost);
}


int n=128;


void floyed()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
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
		if(c<cost[a][b])
			cost[a][b]=cost[b][a]=c;
	}
	floyed();
	char sol=min_element(cost['Z']+'A', cost['Z']+'Z')-cost['Z'];
	printf("%c %d\n",sol,cost['Z'][sol]);
	return 0;
}
