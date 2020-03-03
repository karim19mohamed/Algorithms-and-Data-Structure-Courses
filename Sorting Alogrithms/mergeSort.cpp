#include <iostream>
#include <stdio.h>

using namespace std;
long long n,arr[100009];

void merging(long long ia,long long ja,long long ib,long long jb){
    long long sa=ja-ia+1,sb=jb-ib+1;
    long long arra[sa],arrb[sb];
    long long ka=0,kb=0;
    for (long long i=ia;i<ja+1;i++){
        arra[ka++]=arr[i];
    }
    for (long long i=ib;i<jb+1;i++){
        arrb[kb++]=arr[i];
    }

    long long numa=0,numb=0;
    while(numa!=ka && numb!=kb){
        if (arra[numa]<=arrb[numb]){
            ia++;
            numa++;
        }else{
            arr[ia]=arrb[numb];
            numb++;
            ia++;
        }
    }
    if (numa!=ka){
        for (long long i=numa;i<ka;i++){
            arr[ia]=arra[i];
            ia++;
        }
    }else if (numb!=kb){
        for (long long i=numb;i<kb;i++){
            arr[ia]=arrb[i];
            ia++;
        }
    }
}
void mergeSort(long long i,long long j){
    if (i==j) return;
    mergeSort(i,i+((j-i)/2));
    mergeSort(i+((j-i)/2)+1,j);
    merging(i,i+((j-i)/2),i+((j-i)/2)+1,j);
}

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    mergeSort(0,n-1);
    for (long long i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
    return 0;
}
