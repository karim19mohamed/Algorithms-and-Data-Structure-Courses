#include <iostream>
#include <stdio.h>

using namespace std;
long long n,arr[100009],k,b[100009];

long long binary(long long num){
    long long i=0,j=n-1,m;
    while (i<=j){
        m=i+(j-i)/2;
        if (arr[m]>num) j=m-1;
        else if (arr[m]<num) i=m+1;
        else return m;
    }
    return -1;
}
long long binary_rec(long long i,long long j,long long num){
    if (i>j) return -1;

    long long m=i+(j-i)/2;
    if (arr[m]>num) binary_rec(i,m-1,num);
    else if (arr[m]<num) binary_rec(m+1,j,num);
    else return m;
}

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    scanf("%lld",&k);
    for (long long i=0;i<k;i++){
        scanf("%lld",&b[i]);
    }
    for (long long i=0;i<k;i++){
        //long long ans=binary(b[i]);
        printf("%lld",binary(b[i]));
        if (i!=k-1) printf(" ");
    }
    /*
    printf("\n");
    for (long long i=0;i<k;i++){
        //long long ans=binary_rec(0,n-1,b[i]);
        printf("%lld",binary_rec(0,n-1,b[i]));
        if (i!=k-1) printf(" ");
    }
    */
    return 0;
}

