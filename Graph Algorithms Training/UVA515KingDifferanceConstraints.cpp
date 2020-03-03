/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 101, M = 100;
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

int dist[N];
int n = 128;

const int N2 = 1 << (int) ceil(log(N) / log(2)), N2M1 = N2 - 1;
int q[N2], qsz, frnt, bk;
int inQ[N], inqid;

bool bellman() {
	memset(dist, 0, n * sizeof dist[0]);

	qsz = bk = frnt = 0;
	inqid++;
	for(int src=0;src<n;src++)
		q[bk] = src, qsz++, bk = ++bk & N2M1, inQ[src] = inqid;
	int nn = n;
	while (qsz && nn--) {
		int s = qsz;
		while (s--) {
			int f;
			f = q[frnt], qsz--, frnt = ++frnt & N2M1, inQ[f] = 0;
			for (int k = head[f]; ~k; k = nxt[k]) {
				int t = to[k], c = cost[k];
				int d = dist[f] + c;
				if (dist[t] > d) {
					dist[t] = d;
					if (!nn)
						return false;
					if (inQ[t] != inqid)
						q[bk] = t, qsz++, bk = ++bk & N2M1, inQ[t] = inqid;
				}
			}
		}
	}
	return true;
}

int main() {
	freopen("test.in", "rt", stdin);
	//freopen("comehome.out", "wt", stdout);
	int m;
	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		init(++n);
		while (m--) {
			int si, sj, k;
			char arr[3];
			scanf("%d%d%s%d", &si, &sj, arr, &k);
			sj += si;
			si--;
			if (arr[0] == 'g')
				swap(si, sj), k *= -1;
			k--;
			addEdge(si, sj, k);
		}
		if (bellman())
			puts("lamentable kingdom");
		else
			puts("successful conspiracy");
	}
	return 0;
}
