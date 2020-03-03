#include <iostream>
#include <stdio.h>

using namespace std;
long long n,arr[100009];

void selectionSort(){
    long long minIndx;
    for (long long i=0;i<n;i++){
        minIndx=i;
        for (long long j=i+1;j<n;j++){
            if (arr[j]<arr[minIndx]) minIndx=j;
        }
        if (arr[i]!=arr[minIndx]) swap(arr[i],arr[minIndx]);
    }
}

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    selectionSort();
    for (long long i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
    return 0;
}
