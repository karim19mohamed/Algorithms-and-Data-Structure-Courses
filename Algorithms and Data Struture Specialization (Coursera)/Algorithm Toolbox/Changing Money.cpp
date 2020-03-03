#include <iostream>

using namespace std;
long long m;
long long arr[3]={10,5,1};
long long stps;
int i=0;

int main()
{
    cin >> m;
    long long out_m=0;
    while (1){
        out_m=m-arr[i];
        if (out_m>=0){
            stps++;
            m=out_m;
        }else{
            i++;
        }
        if (out_m<0 && i>2){
            break;
        }
    }
    cout << stps << endl;
    return 0;
}
