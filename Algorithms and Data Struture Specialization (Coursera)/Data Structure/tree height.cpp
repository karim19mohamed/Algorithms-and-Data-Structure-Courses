#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long n,a,rt,res;
vector <long long> aj[100009];
bool ves[100009];

long long kkk (long long u){
    ves[u]=1;
    long long ans=0;
    for (long long i=0;i<aj[u].size();i++){
        if (ves[ aj[u][i] ]==0) ans=max(kkk(aj[u][i]),ans);
    }
    return ans+1;
}

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        cin >> a;
        if (a!=-1) aj[a].push_back(i);
        else rt=i;
    }
    res=kkk(rt);
    cout << res << endl;
    return 0;
}
