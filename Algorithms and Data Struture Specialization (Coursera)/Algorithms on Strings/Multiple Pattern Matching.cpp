#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
const long long mx=5e5+9;
long long nodeCount,child[mx][100],childCount[mx];
long long n;
string ss,sr;
bool le[mx];

long long addNode(){
    memset(child[nodeCount],-1,sizeof(child[nodeCount]));
    childCount[nodeCount]=0;
    return nodeCount++;
}
void insrt (string s){
    long long cur=0;
    for (long long i=0;i<s.size();++i){
        long long nxt=child[cur][s[i]];
        if (nxt==-1){
            nxt=child[cur][s[i]]=addNode();
            childCount[cur]++;
        }
        cur=nxt;
    }
    le[cur]=1;
}
void init(){
    nodeCount=0;
    addNode();
}
bool matching(long long indx){
    long long cur=0;
    for (long long i=indx;i<sr.size();++i){
        long long nxt=child[cur][sr[i]];
        if (le[cur]){
            return 1;
        }
        if (nxt==-1){
            return 0;
        }
        cur=nxt;
    }
    if (le[cur]){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    cin >> sr;
    scanf("%lld",&n);
    init();
    while(n--){
        cin >> ss;
        insrt(ss);
    }
    bool z=0;
    for (long long i=0;i<sr.size();++i){
        if (matching(i)){
            if (z){
                printf(" ");
            }
            z=1;
            printf("%lld",i);
        }
    }
    printf("\n");
    return 0;
}
