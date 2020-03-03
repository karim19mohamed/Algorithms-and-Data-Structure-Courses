#include <iostream>

using namespace std;
long long n;
//long long ans=1000009;
long long iter=0;
long long cal(long long num);


int main()
{
    cin >> n;
    long long solution;
    solution=cal(1);
    cout << solution << endl;
    return 0;
}
long long cal(long long num){
    //cout << num << "    " << ans << endl;
    if (num==n) return 0;
    long long ans=1000009;

    if (num*2<=n) {
        ans=min(ans,cal(num*2)+1);
        //cout << "2          " << ans << endl;
    }
    if (num*3<=n) {
        ans=min(ans,cal(num*3)+1);
        //cout << "3          " << ans << endl;
    }
    if (num+1<=n) {
        ans=min(ans,cal(num+1)+1);
        //cout << "1          " << ans << endl;
    }
    return ans;
}
