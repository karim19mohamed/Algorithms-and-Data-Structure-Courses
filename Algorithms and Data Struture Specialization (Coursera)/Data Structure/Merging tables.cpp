#include <iostream>
#include <cmath>

using namespace std;
long long n,m,x,y;
long long arr[100009];
long long p[100009];
long long ran[100009];
long long ans,res;

class UnionFind{
    public:
    UnionFind (long long N){
        for (long long i=0;i<N;i++) p[i]=i;
    }
    int findSet (long long i){
        return (p[i]==i)? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet (long long i,long long j){
        return findSet(i)==findSet(j);
    }
    void unionSet (long long i,long long j){
        if (!isSameSet(i,j)){
            long long a=findSet(i);
            long long b=findSet(j);
            res=arr[a]+arr[b];
            arr[a]=res;arr[b]=res;
            ans=max(ans,res);
            if (ran[a]>ran[b]){
                p[b]=a;
            }else{
                p[a]=b;
                if (ran[a]==ran[b]) ran[b]++;
            }
        }
    }
};

int main()
{
    cin >> n >> m;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
        ans=max(ans,arr[i]);
    }
    UnionFind UF(n);
    for (long long i=0;i<m;i++){
        cin >> x >> y;
        UF.unionSet(x-1,y-1);
        cout << ans << endl;
    }
    return 0;
}
