#include <iostream>
#include <list>

using namespace std;
long long n,m,res,ss;
string a,b;
long long c,num;
long long p=1000000007;
long long x=263;
list <string> arr[100009];
long long hashing (string w);

int main()
{
    cin >> m >> n;
    for (long long i=0;i<n;i++){
        cin >> a;
        if (a=="add"){
            bool z=0;
            cin >> b;
            num=hashing(b);
            for (std::list<string>::iterator it=arr[num].begin();it!=arr[num].end();++it){
                if (*it==b) z=1;
            }
            if (!z) arr[num].push_front(b);
        }else if (a=="del"){
            cin >> b;
            num=hashing(b);
            arr[num].remove(b);
        }else if (a=="find"){
            cin >> b;
            bool q=0;
            num=hashing(b);
            for (std::list<string>::iterator it=arr[num].begin();it!=arr[num].end();++it){
                if (*it==b) q=1;
            }
            if (q) cout << "yes" << endl;
            else cout << "no" << endl;
        }else{
            cin >> c;
            ss=arr[c].size();
            for (std::list<string>::iterator it=arr[c].begin();it!=arr[c].end();++it){
                cout << *it;
                ss--;
                if (ss!=0) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
long long hashing (string w){
    res=0;
    for (long long i=w.size()-1;i>-1;i--){
        res=(res*x+w[i]+p)%p;
    }
    //res=res%p;
    res=(res+m)%m;
    //cout << res << endl;
    return res;
}
