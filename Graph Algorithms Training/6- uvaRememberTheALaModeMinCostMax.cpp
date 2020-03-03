/*
 TASK: comehome
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 50 * 50 * 2 + 100 * 2;
int head[N], nxt[M], from[M], to[M], cost[M], cap[M], capBackup[M], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t, int cst, int cp) {
	nxt[ne] = head[f];
	to[ne] = t;
	from[ne] = f;
	cost[ne] = cst;
	cap[ne] = cp;
	head[f] = ne++;
}
void addAugEdge(int a, int b, int cst, int cp) {
	addEdge(a, b, cst, cp);
	addEdge(b, a, -cst, 0);
}

int dist[N];
int flow[N];
int par[N];
int n = 128;

const int N2 = 128, N2M1 = N2 - 1;
int q[N2], qsz, frnt, bk;
int inQ[N], inqid;

bool bellman(int src) {
	memset(dist, 0x3f, n * sizeof dist[0]);
	memset(flow, 0, n * sizeof flow[0]);
	dist[src] = 0;
	flow[src] = 0x3f3f3f3f;
	qsz = bk = frnt = 0;
	inqid++;
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
				if (cap[k] && dist[t] > d) {
					dist[t] = d;
					flow[t] = min(flow[f], cap[k]);
					par[t] = k;
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
pair<int, int> minCostMaxFlow(int src, int snk) {
	int cst = 0, fl = 0;
	while (1) {
		bellman(src);
		if (!flow[snk])
			break;
		fl += flow[snk];
		cst += dist[snk] * flow[snk];
		for (int i = snk; i != src; i = from[par[i]]) {
			int k = par[i];
			cap[k] -= flow[snk];
			cap[k ^ 1] += flow[snk];
		}
	}
	return {cst,fl};
}
int main() {
	freopen("test.in", "rt", stdin);
	int P, I, tc = 1;
	while (scanf("%d%d", &P, &I), P || I) {
		n = P + I + 2;
		init(n);
		int src = n - 2, snk = src + 1;
		for (int i = 0; i < P; i++) {
			int cp;
			scanf("%d", &cp);
			addAugEdge(src, i, 0, cp);
		}
		for (int i = 0; i < I; i++) {
			int cp;
			scanf("%d", &cp);
			addAugEdge(i + P, snk, 0, cp);
		}
		for (int i = 0; i < P; i++)
			for (int j = 0; j < I; j++) {
				double cp;
				scanf("%lf", &cp);
				if (cp == -1)
					continue;
				int cst = cp * 100 + .5;
				addAugEdge(i, P+j, cst, 0x3f3f3f3f);
			}
		memcpy(capBackup, cap, ne * sizeof cap[0]);
		pair<int, int> mn = minCostMaxFlow(src, snk);
		memcpy(cap, capBackup, ne * sizeof cap[0]);
		for(int i=0;i<ne;i++)
			cost[i]*=-1;
		pair<int, int> mx = minCostMaxFlow(src, snk);
		printf("Problem %d: %.2lf to %.2lf\n",tc++,mn.first/100.0,mx.first/-100.0);
	}
	return 0;
}
