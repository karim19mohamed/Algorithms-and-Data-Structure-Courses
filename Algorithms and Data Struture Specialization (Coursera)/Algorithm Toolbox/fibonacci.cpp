#include <iostream>

using namespace std;
long long fib (int n);

int main()
{
    int n;
    cin >> n ;
    long long ans;
    ans=fib (n);
    cout << ans << endl;
    return 0;
}

long long fib (int n){
    if (n<2){
        return n;
    }else{
        long long ans_1=1;
        long long ans_2=0;
        long long ans;
        for (int i=1;i<n;i++){
            ans=ans_2+ans_1;
            ans_2=ans_1;
            ans_1=ans;
        }
        return ans;
    }

}
