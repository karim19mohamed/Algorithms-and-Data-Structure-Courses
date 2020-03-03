#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;
const int mx = 1e5+9;
int childCount[mx],nodeCount,child[mx][190];
bool isEnd[mx];
int t,n;
string ss;

int addNode(){
    memset(child[nodeCount],-1,sizeof(child[nodeCount]));
    isEnd[nodeCount]=0;
    childCount[nodeCount]=0;
    return nodeCount++;
}

void insrt(string s){
    int cur=0;
    for (int i=0;i<s.size();++i){
        int nxt=child[cur][s[i]];
        if (nxt==-1){
            nxt=addNode();
            child[cur][s[i]]=nxt;
            childCount[cur]++;
        }
        cur=nxt;
    }
    isEnd[cur]=1;
}

int init(){
    nodeCount=0;
    addNode();
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        for (int i=0;i<n;i++){
            cin >> ss;
            insrt(ss);
        }
        for (int i=0;i<nodeCount;i++){
            if (isEnd[i] && childCount[i]){
                printf("NO\n");
                goto ou;
            }
        }
        printf("YES\n");
        ou: ;
    }
    return 0;
}

