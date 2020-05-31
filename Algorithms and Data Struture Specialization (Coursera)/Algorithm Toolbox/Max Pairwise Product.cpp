#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

ll MaxPairwiseProduct(const std::vector<ll>& numbers) {
    int idx1=0,num1=0,idx2=0,num2=0;
    for (int i = 0; i < numbers.size(); ++i) if(num1<numbers[i]) idx1=i,num1=numbers[i];
    for (int i = 0; i < numbers.size(); ++i) if(num2<numbers[i] && idx1!=i) idx2=i,num2=numbers[i];
    return numbers[idx1]*numbers[idx2];
}

int main() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}









