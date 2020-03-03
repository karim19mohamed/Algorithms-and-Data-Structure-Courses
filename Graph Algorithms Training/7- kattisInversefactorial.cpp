//https://nus.kattis.com/problems/inversefactorial
#include <bits/stdc++.h>

using namespace std;

char in[(int) 1e6 + 1];
int Count5(int x) {
	int res = 0;
	while (x) {
		res += x / 5;
		x /= 5;
	}
	return res;
}
char str[20];
long long fastMul(long long a,int m,long long mod){
	long long res=0;
	while(m){
		if(m&1)
			res=(res+a)%mod;
		a=(a+a)%mod;
		m>>=1;
	}
	return res;
}
int main() {
	freopen("test.in", "rt", stdin);
	scanf("%s", in);
	int len = strlen(in);
	int countz = 0;
	while (in[len - 1] == '0')
		countz++, len--;
	int st = 1, e = 5e6;
	while (st < e) {
		int mid = st + (e - st) / 2;
		if (Count5(mid) >= countz)
			e = mid;
		else
			st = mid + 1;
	}
	long long f = 1;
	//10888869450418352160768000000
	//     ^                 ^
	//     |                 |
	//     j                len
	int j = max(len - 18, 0);
	char *c = in + j;
	while(*c=='0')c++;
	//10888869450418352160768\000000
	//     ^                 ^
	//     |                 |
    //     j                len

	in[len]='\0';
	int cc = 0;
	for (int x = st; x > 1; x--) {
		int xx = x;
		while (xx % 5 == 0) {
			cc++;
			xx /= 5;
		}
		while (cc && xx % 2 == 0) {
			cc--;
			xx /= 2;
		}
		f = fastMul(f , xx,1e18) % ((long long) 1e18);
	}
	while (sprintf(str, "%lld", f), strcmp(str, c)) {
		f =fastMul(f , ++st,1e18);
	}

	printf("%d\n", st);
	return 0;
}
