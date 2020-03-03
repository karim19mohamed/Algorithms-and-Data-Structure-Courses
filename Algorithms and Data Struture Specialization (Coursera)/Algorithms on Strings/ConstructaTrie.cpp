#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <set>

using namespace std;
const int mx=1e4+9;
set<pair<int,pair<int,char> > > myset;
set<pair<int,pair<int,char> > >::iterator it;
int nodeCount,child[mx][100],childCount[mx];
int n;
string ss;

int addNode(){
    memset(child[nodeCount],-1,sizeof(child[nodeCount]));
    childCount[nodeCount]=0;
    return nodeCount++;
}
void insrt (string s){
    int cur=0;
    for (int i=0;i<s.size();++i){
        int nxt=child[cur][s[i]];
        if (nxt==-1){
            nxt=child[cur][s[i]]=addNode();
            childCount[cur]++;
        }
        myset.insert({cur,{nxt,s[i]}});
        cur=nxt;
    }
}
int init(){
    nodeCount=0;
    addNode();
}


int main()
{
    scanf("%d",&n);
    init();
    while(n--){
        cin >> ss;
        insrt(ss);
    }
    for (it=myset.begin(); it!=myset.end(); ++it){
        pair <int,pair<int,char> > m=*it;
        printf("%d->%d:%c\n",m.first,m.second.first,m.second.second);
    }
    return 0;
}
