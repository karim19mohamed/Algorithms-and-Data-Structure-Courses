#include <iostream>
#include <queue>

using namespace std;
long long n,m;
long long arr[100009];
priority_queue < pair<long long,long long> > q;

int main()
{
    cin >> n >> m;
    for (long long i=0;i<m;i++) cin >> arr[i];
    for (long long i=0;i<n;i++) q.push(make_pair(0,-1*i));
    for (long long i=0;i<m;i++){
        pair <long long,long long> u=q.top();
        q.pop();
        cout << -1*u.second << " " << -1*u.first << endl;
        u.first-=arr[i];
        q.push(u);
    }
    return 0;
}
