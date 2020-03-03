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

int res[N], resSz;
int deg[N];

void topo() {
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++)
		if (!deg[i])
			q.push(i);
	resSz = 0;
	while (q.size()) {
		int i = q.top();
		q.pop();
		res[resSz++] = i;
		for (int k = head[i]; ~k; k = nxt[k]) {
			int j = to[k];
			if (!--deg[j])
				q.push(j);
		}
	}
}
int main() {
	freopen("agrinet.in", "rt", stdin);
	int tc = 1;
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
		//sort(&names[0],&names[0]+n);
		//for(auto& a:names)get(a);
		int m;
		scanf("%d", &m);
		memset(deg, 0, n * sizeof(deg[0]));
		while (m--) {
			char arr[52];
			scanf("%s", arr);
			int f = get(arr);
			scanf("%s", arr);
			int t = get(arr);
			deg[t]++;
			addEdge(f, t);
		}
		topo();
		printf("Case #%d: Dilbert should drink beverages in this order:", tc++);
		for (int i = 0; i < n; i++)
			printf(" %s", names[res[i]].c_str());
		puts(".");
		puts("");
	}
	return 0;
}
