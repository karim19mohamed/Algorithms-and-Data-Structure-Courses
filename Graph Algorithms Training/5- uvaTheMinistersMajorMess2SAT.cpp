/*
 TASK: schlnet
 LANG: C++11
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 200;
bool mat[N][N];
int n;
void init() {
	memset(mat, 0, sizeof mat);
}
void addEdge(int a, int b) {
	mat[a][b] = 1;
}

#define VAR(ID) ((ID)<<1)
#define NOTVAR(ID) (VAR(ID)|1)
#define NOT(ID) ((ID)^1)

void addOr(int v1, int v2) {
	addEdge(NOT(v1), v2);
	addEdge(NOT(v2), v1);
}

void addXor(int v1, int v2) {
	addOr(v1, v2);
	addOr(NOT(v1), NOT(v2));
}

void addImplication(int v1, int v2) {
	addOr(NOT(v1), v2);
}
void transtive() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] |= mat[i][k] && mat[k][j];
}
int res[N >> 1];

bool getSolution() {
	memset(res, -1, (n >> 1) * sizeof res[0]);
	for (int i = 0; i < (n >> 1); i++)
		if (mat[VAR(i)][NOTVAR(i)] && mat[NOTVAR(i)][VAR(i)])
			return false;
		else if (mat[VAR(i)][NOTVAR(i)])
			res[i] = 0;
		else if (mat[NOTVAR(i)][VAR(i)])
			res[i] = 1;
	return true;
}

int main() {
	freopen("test.in", "rt", stdin);
	int b, m, t = 0;
	while (++t, scanf("%d%d", &b, &m), b || m) {
		n = b << 1;
		init();
		while (m--) {
			int c;
			scanf("%d", &c);
			int a[4];
			for (int i = 0; i < c; i++) {
				int qid;
				char v;
				scanf("%d %c", &qid, &v);
				qid--;
				a[i] = v == 'y' ? VAR(qid) : NOTVAR(qid);
			}
			if (c < 3) {
				for (int i = 0; i < c; i++)
					addOr(a[i], a[i]);
			} else {

				for (int i = 0; i < c; i++)
					for (int j = 0; j < c; j++)
						if (i != j)
							addImplication(NOT(a[i]), a[j]);
			}

		}
		transtive();
		printf("Case %d: ", t);
		if (!getSolution())
			printf("impossible");
		else
			for (int i = 0; i < (n >> 1); i++)
				printf("%c", res[i] == -1 ? '?' : (res[i] ? 'y' : 'n'));
		puts("");
	}
}
