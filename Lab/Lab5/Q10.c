#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int getMax(int* arr,int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
void countingsort(int* arr,int n,int exp){
    int opt[n];
    int cnt[10];
    for(int i=0;i<10;i++){
        cnt[i]=0;
    }
    //Count Digits
    for(int i=0;i<n;i++){
        int digit = ((arr[i])/exp)%10;
        cnt[digit]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/exp)%10;
        opt[cnt[digit]-1] = arr[i];//0 based indexing
        cnt[digit]--;
    }
    //opt array
    for(int i=0;i<n;i++){
        arr[i]=opt[i];
    }
}
void radixsort(int* arr,int n){
    int max = getMax(arr,n);
    for(int exp=1;max/exp>0;exp*=10){
        countingsort(arr,n,exp);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // int max = 0;
    // for(int i=0;i<n;i++){
    //     int a = arr[i];
    //     int cnt=0;
    //     while(a){
    //         cnt++;
    //         a/=10;
    //     }
    //     if(max<cnt){
    //         max = cnt;
    //     }
    // }Other mthd for getMax
    radixsort(arr,n);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}