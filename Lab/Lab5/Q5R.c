#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int t = *a;
    *a=*b;
    *b=t;
}
int divisor(int n){
    int sum =0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            sum++;
            int j = n/i;
            if(i!=j){
                sum++;
            }
        }
    }
    return sum;
}

void bubblesort(int* arr,int* d,int n){
    int swapped  =0;
    do{
        swapped = 0;
        for(int i=0;i<n-1;i++){
            if(d[i+1]!=d[i]&&d[i+1]<d[i]){
                swap(&arr[i],&arr[i+1]);
                swap(&d[i],&d[i+1]);
                swapped = 1;
                continue;
            }
            else if(d[i+1]==d[i]&&arr[i+1]>arr[i]){
                swap(&arr[i+1],&arr[i]);
                swap(&d[i],&d[i+1]);
                swapped = 1;
                continue;
            }
            
        }
    }while(swapped = 1);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int d[n];
    for(int i=0;i<n;i++){
        d[i]=divisor(a[i]);
    }
    bubblesort(a,d,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
        printf("\n");
        


    return 0;
}