#include <iostream>
#include <string>
#include <stack>

using namespace std;
string p,s;
long long hp,y,res,num;
long long ht[500009];
stack <long long> ans;
long long ppp=1000000009;
long long x=5;
long long hashing (string w);
void rabin();
bool areEqual (long long w);

int main()
{
    cin >> p >> s;
    hp=hashing(p)%ppp;
    rabin();
    while (!ans.empty()){
        cout << ans.top();
        ans.pop();
        if (ans.size()!=0) cout << " ";
    }
    cout << endl;
    return 0;
}
void rabin(){
    y=1;
    num=s.size()-p.size();
    string q=s.substr(num,p.size());
    ht[num]=hashing(q);
    for (long long i=0;i<p.size();i++) y=y*x;
    for (long long i=num-1;i>-1;i--){
        ht[i]=ht[i+1]*x+s[i]-s[i+p.size()]*y;
        //cout << ht[i] << "  " << ht[i+1]*x << "  " << s[i+p.size()-1] << endl;
    }
    for (long long i=num;i>-1;i--){
        ht[i]=ht[i]%ppp;
        if (ht[i]==hp){
            if (areEqual(i)) ans.push(i);
        }
    }
}
long long hashing (string w){
    res=0;
    for (int i=w.size()-1;i>-1;i--){
        res=(res*x+w[i]);
    }
    //res=res%ppp;
    //cout << res << endl;
    return res;
}
bool areEqual (long long w){
    for (long long i=0;i<p.size();i++){
        //cout << p[i] << " "  << s[w+i] << endl;
        if (p[i]!=s[w+i]) return 0;
    }
    return 1;
}
