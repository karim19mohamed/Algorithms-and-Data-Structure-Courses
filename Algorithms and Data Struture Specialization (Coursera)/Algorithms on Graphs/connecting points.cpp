#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;
int n,a,b,w;
long double x_f,y_f,x_e,y_e,c;
long double ans;
vector <pair<int,int> > points;
priority_queue <pair<long double,pair<int,int> > > edgeList;

class UnionFind {
    public:
        vector <int> vi;
        int p[209];
        int ran[209];
        UnionFind (int N){
            for (int i=0;i<N;i++) {
                p[i]=i;
                ran[i]=0;
            }
        }
        int findSet(int i){
            return (p[i]==i) ? i : ( p[i]=findSet(p[i]) );
        }
        bool isSameSet(int i,int j){
            return findSet(i)==findSet(j);
        }
        void unionSet(int i,int j){
            if (!isSameSet(i,j)){
                int x=findSet(i), y=findSet(j);
                if (ran[x]>ran[y]) p[y]=x;
                else{
                    p[x]=y;
                    if (ran[x]==ran[y]) ran[y]++;
                }
            }
        }
};

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        points.push_back(make_pair(a,b));
        w++;
    }
    for (int i=0;i<n;i++){
        x_f=points[i].first;
        y_f=points[i].second;
        for (int j=i+1;j<n;j++){
            x_e=points[j].first;
            y_e=points[j].second;
            c=sqrt((x_f-x_e)*(x_f-x_e)+(y_f-y_e)*(y_f-y_e));
            edgeList.push(make_pair(-1*c,make_pair(i,j)));
        }
    }
    UnionFind UF(n);
    while (!edgeList.empty()){
        pair <int,int> u=edgeList.top().second;
        if (!UF.isSameSet(u.first,u.second)){
            ans+=edgeList.top().first;
            UF.unionSet(u.first,u.second);
        }
        edgeList.pop();
    }
    printf("%.7Lf\n",-1*ans);
    //cout << -1*ans << endl;
    return 0;
}








