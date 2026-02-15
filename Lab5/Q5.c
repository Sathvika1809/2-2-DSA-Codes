#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int*a,int* d,int n){
    int swapped = 0;
    do{
        swapped = 0;
    for(int i=0;i<n;i++){
        if(d[i+1]!=d[i]&&d[i+1]<d[i]){
            swap(&a[i],&a[i+1]);
            swap(&d[i],&d[i+1]);
        swapped = 1;
        continue;
    }else if(d[i+1]==d[i] && a[i+1]>a[i]){
        swap(&a[i],&a[i+1]);
        swap(&d[i],&d[i+1]);
        swapped = 1;
        continue;
    }
}
}while(swapped);
}
int divisor(int n){
    int sum = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            sum++;
            int j = n/i;
            if(i!=j)sum++;
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int d[n];
    for(int i=0;i<n;i++){
        d[i] = divisor(arr[i]);
    }
    bubble(arr,d,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}