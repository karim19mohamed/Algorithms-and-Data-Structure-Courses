#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>

using namespace std;
int n,k,a,b,ww;
double x_f,y_f,x_e,y_e,c;
double ans=0;
vector <pair<int,int> > points;
priority_queue <pair<long double,pair<int,int> > > pq;

class UnionFind{
    public:
    int p[309];
    int ran[309];
    UnionFind (int N){
        for (int i=0;i<N;i++){
            ran[i]=0;p[i]=i;
        }
    }
    int findSet (int i){
        return (p[i]==i) ? i: p[i]=findSet(p[i]);
    }
    bool isSameSet (int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet (int i,int j){
        if (!isSameSet(i,j)){
            int x=findSet(i);
            int y=findSet(j);
            if (ran[x]>ran[y]) p[y]=x;
            else {
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
    }
    cin >> k;
    for (int i=0;i<n;i++){
        x_f=points[i].first;
        y_f=points[i].second;
        for (int j=i+1;j<n;j++){
            x_e=points[j].first;
            y_e=points[j].second;
            c=sqrt((x_f-x_e)*(x_f-x_e)+(y_f-y_e)*(y_f-y_e));
            pq.push(make_pair(-1*c,make_pair(i,j)));
        }
    }

    UnionFind UF(n);
    ww=n;
    while (ww!=k && !pq.empty()){
        pair <int,int> u=pq.top().second;
        pq.pop();
        if (!UF.isSameSet(u.first,u.second)){
            UF.unionSet(u.first,u.second);
            ww--;
        }
    }
    while (!pq.empty()){
        pair <int,int> u=pq.top().second;
        pq.pop();
        if (!UF.isSameSet(u.first,u.second)){
            ans=pq.top().first;
            break;
        }
    }
    if (ans!=0) printf("%.9f\n",-1*ans);
    else printf("%.9f\n",ans);
    return 0;
}
