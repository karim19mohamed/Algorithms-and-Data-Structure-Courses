#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long long n,arr[100009];

long long partit(long long l,long long h,long long pivot){
    long long num=l;
    for (long long i=l+1;i<h+1;i++){
        if (arr[i]<arr[pivot]){
            num++;
            swap(arr[i],arr[num]);
        }
    }
    swap(arr[pivot],arr[num]);
    return num;
}

void quickSort(long long i,long long j){
    if (i>=j) return;

    long long k=rand() % j + i;
    swap(arr[k],arr[i]);
    long long num=partit(i,j,i);
    quickSort(i,num-1);
    quickSort(num+1,j);
}
void quickSortMoreParts(long long i,long long j){
    if (i>=j) return;

    long long k=rand() % j + i;
    swap(arr[k],arr[i]);
    long long numa=partit(i,j,i);
    k=rand() % j + i;
    swap(arr[k],arr[i]);
    long long numb=partit(i,j,i);

    if (numa>numb) swap(numa,numb);
    quickSort(i,numa-1);
    quickSort(numa+1,numb-1);
    quickSort(numb+1,j);
}

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    quickSortMoreParts(0,n-1);
    for (long long i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
    return 0;
}
