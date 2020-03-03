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
int n = 128;

const int N2 = 1 << (int) ceil(log(N) / log(2)), N2M1 = N2 - 1;
int q[N2], qsz, frnt, bk;
int inQ[N],inqid;

bool bellman(int src) {
	memset(dist, 0x3f, n * sizeof dist[0]);
	dist[src] = 0;
	qsz = bk = frnt = 0;
	inqid++;
	q[bk] = src, qsz++, bk = ++bk & N2M1,inQ[src]=inqid;
	int nn = n;
	while (qsz && nn--) {
		int s = qsz;
		while (s--) {
			int f;
			f = q[frnt], qsz--, frnt = ++frnt & N2M1,inQ[f]=0;
			for (int k = head[f]; ~k; k = nxt[k]) {
				int t = to[k], c = cost[k];
				int d = dist[f] + c;
				if (dist[t] > d) {
					dist[t] = d;
					if(!nn)return false;
					if(inQ[t]!=inqid)
						q[bk] = t, qsz++, bk = ++bk & N2M1,inQ[t]=inqid;
				}
			}
		}
	}
	return true;
}

int main() {
	freopen("comehome.in", "rt", stdin);
	freopen("comehome.out", "wt", stdout);
	int m;
	scanf("%d", &m);
	init(n);
	while (m--) {
		char a, b;
		int c;
		scanf(" %c %c%d", &a, &b, &c);
		addBiEdge(a, b, c);
	}
	bellman('Z');
	char sol = min_element(dist + 'A', dist + 'Z') - dist;
	printf("%c %d\n", sol, dist[sol]);
	return 0;
}
