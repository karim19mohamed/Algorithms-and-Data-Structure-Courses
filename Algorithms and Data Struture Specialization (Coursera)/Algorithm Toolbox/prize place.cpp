#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
long long n;
queue <long long> k;
long long ans;

int main()
{
    cin >> n;
    long long i=0;
    while (n!=0){
        i=i+1;
        //cout << ceil(n/2) << endl;
        if (n-i>i){
            k.push(i);
            n-=i;
            ans++;
        }else{
            k.push(n);
            n=0;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i=0;i<ans;i++){
        cout << k.front() << " ";
        k.pop();
    }
    return 0;
}
