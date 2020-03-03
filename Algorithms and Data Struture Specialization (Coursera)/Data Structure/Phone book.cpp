#include <iostream>
#include <map>
#include <string>

using namespace std;
string s,name;
long long n,num;
map <long long,string> arr;

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        cin >> s;
        if (s=="add"){
            cin >> num >> name;
            arr[num]=name;
        }else if (s=="find"){
            cin >> num;
            if (arr[num].size()!=0) cout << arr[num] << endl;
            else cout << "not found" << endl;
        }else{
            cin >> num;
            arr[num]="";
        }
    }
    return 0;
}
