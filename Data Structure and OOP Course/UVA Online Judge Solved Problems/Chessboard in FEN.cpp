#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=8;
string s;
char arr[N][N];
bool chess_board[N][N];
void reset (){
	for (int i=0;i<N;++i){
		memset(chess_board[i], 0, N);
		memset(arr[i], '0', N);
	}
}
void king(int x,int y){
	for (int i=-1;i<2;++i)
		for (int j=-1;j<2;++j)
			if (x+i<N && y+j<N && x+i>=0 && y+j>=0) chess_board[x+i][y+j]=1;
}
void elephant(int x,int y){
	chess_board[x][y]=1;
	int x_tmp=x-1,y_tmp=y-1;
	while (x_tmp>=0 && y_tmp>=0 && arr[x_tmp][y_tmp]=='0') chess_board[x_tmp--][y_tmp--]=1;
	x_tmp=x+1,y_tmp=y+1;
	while (x_tmp<N && y_tmp<N && arr[x_tmp][y_tmp]=='0') chess_board[x_tmp++][y_tmp++]=1;
	x_tmp=x+1,y_tmp=y-1;
	while (x_tmp<N && y_tmp>=0 && arr[x_tmp][y_tmp]=='0') chess_board[x_tmp++][y_tmp--]=1;
	x_tmp=x-1,y_tmp=y+1;
	while (y_tmp<N && x_tmp>=0 && arr[x_tmp][y_tmp]=='0') chess_board[x_tmp--][y_tmp++]=1;
}
void horse (int x,int y){
	int a[9]={x,x+2,x+2,x+1,x+1,x-2,x-2,x-1,x-1};
	int b[9]={y,y-1,y+1,y+2,y-2,y-1,y+1,y+2,y-2};
	for (int i=0;i<9;++i)
		if (a[i]<N && b[i]<N && a[i]>=0 && b[i]>=0) chess_board[a[i]][b[i]]=1;
}
void tower (int x,int y){
	chess_board[x][y]=1;
	int x_tmp=x-1,y_tmp=y;
	while (x_tmp>=0 && arr[x_tmp][y]=='0') chess_board[x_tmp--][y]=1;
	y_tmp=y-1;
	while (y_tmp>=0 && arr[x][y_tmp]=='0') chess_board[x][y_tmp--]=1;
	x_tmp=x+1;
	while (x_tmp<N && arr[x_tmp][y]=='0') chess_board[x_tmp++][y]=1;
	y_tmp=y+1;
	while (y_tmp<N && arr[x][y_tmp]=='0') chess_board[x][y_tmp++]=1;
}
void set_board (string s){
	int y=0,x=0;
	for (int i=0;i<(int)s.size();++i){
		if (s[i]=='/'){
			++x;
			y=0;
			continue;
		}
		if (s[i]<58){
			y+=(s[i]-'0');
			continue;
		}
		arr[x][y]=s[i];
		++y;
	}
}

int main() {
	while (cin>>s){
		int ans=0;
		reset ();
		set_board(s);
		/*for (int i=0;i<N;++i){
			for (int j=0;j<N;++j){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i=0;i<N;++i) for (int j=0;j<N;++j){
			char c = arr[i][j];
			if (c=='0') continue;
			if (c=='n' || c=='N') horse(i,j);
			else if (c=='r' || c=='R') tower(i,j);
			else if (c=='b' || c=='B') elephant(i,j);
			else if (c=='k' || c=='K') king(i,j);
			else if (c=='q' || c=='Q') tower(i,j),elephant(i,j);
			else if (c=='p'){
				chess_board[i][j]=1;
				if (i+1<N && j+1<N) chess_board[i+1][j+1]=1;
				if (i+1<N && j-1>=0) chess_board[i+1][j-1]=1;
			}else if (c=='P'){
				chess_board[i][j]=1;
				if (i-1>=0 && j+1<N) chess_board[i-1][j+1]=1;
				if (i-1>=0 && j-1>=0) chess_board[i-1][j-1]=1;
			}
		}
		/*cout << endl;
		for (int i=0;i<N;++i){
			for (int j=0;j<N;++j){
				cout << chess_board[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i=0;i<N;++i) for (int j=0;j<N;++j){
			if (!chess_board[i][j]) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}

















