#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

bool row[10],col[10],dig1[20],dig2[20];
int solution[10],main_col,sol_num;

bool attacked (int x,int y){
	return (row[x] || col[y] || dig1[x+y] || dig2[x-y+8])? 1 : 0;
}
void set_queen(int x,int y){
	row[x]=col[y]=dig1[x+y]=dig2[x-y+8]=1;
	solution[y]=x;
}
void unset_queen(int x,int y){
	row[x]=col[y]=dig1[x+y]=dig2[x-y+8]=0;
}
void print_solution(){
	if (sol_num<10) printf(" ");
	printf("%d      ",sol_num++);
	for (int i=0;i<7;++i) printf("%d ",solution[i]+1);
	printf("%d\n",solution[7]+1);
}

void solve(int q,int col){
	if (col==8){
		if (q==8) print_solution();
		return;
	}
	if (col==main_col){
		solve(q,col+1);
	}else{
		for (int i=0;i<8;++i){
			if (!attacked(i,col)){
				set_queen(i,col);
				solve(q+1,col+1);
				unset_queen(i,col);
			}
		}
	}
}

int main() {
	int t,x,y;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&x,&y);
		puts("SOLN       COLUMN");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		x--,y--;
		main_col=y;
		sol_num=1;
		set_queen(x,y);
		solve(1,0);
		unset_queen(x,y);
		if (t) puts("");
	}
	return 0;
}
















