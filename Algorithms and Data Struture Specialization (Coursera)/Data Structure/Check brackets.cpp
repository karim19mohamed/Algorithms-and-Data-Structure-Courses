#include <iostream>
#include <string>
#include <stack>

using namespace std;
int k,res;
string sm;
stack <pair<char,int> > arr;

int main()
{
    cin >> sm;
    k=sm.size();
    for (int i=0;i<k;i++){
        if (sm[i]=='[' || sm[i]=='{' || sm[i]=='('){
            arr.push(make_pair(sm[i],i+1));
        }else if (sm[i]==']'){
            if (!arr.empty()){
                if (arr.top().first=='[') arr.pop();
                else{
                    res=i+1;
                    break;
                }
            }else{
                res=i+1;
                break;
            }
        }else if (sm[i]=='}'){
            if (!arr.empty()){
                if (arr.top().first=='{') arr.pop();
                else{
                    res=i+1;
                    break;
                }
            }else{
                res=i+1;
                break;
            }
        }else if (sm[i]==')'){
            if (!arr.empty()){
                if (arr.top().first=='(') arr.pop();
                else{
                    res=i+1;
                    break;
                }
            }else{
                res=i+1;
                break;
            }
        }
    }
    if (res!=0){
        cout << res << endl;
    }else if (!arr.empty()){
        //while (arr.size()!=1) arr.pop();
        cout << arr.top().second << endl;
    }else{
        cout << "Success" << endl;
    }
    return 0;
}
