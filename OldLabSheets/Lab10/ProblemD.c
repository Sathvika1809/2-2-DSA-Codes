#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
//just selection sort and we cant swap so reverse two times
void reverse(int* arr,int k){
    int i=0, j=k-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
int findMaxIndex(int* arr,int n){
    int maxIdx = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[maxIdx]){
            maxIdx = i;
        }
    }
    return maxIdx;
}
int main(){

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int flips[2*n];
    int flipCount = 0;

    for(int i=n;i>1;i--){
        int maxIdx = findMaxIndex(arr,n);
        
        if(maxIdx == n-1){
            continue;
        }
        if(maxIdx!=0){
            reverse(a,maxIdx+1);
            flips[flipCount++] = maxIdx+1;
        }
        reverse(arr,n);
        flips[flipCount++]=n;
    }
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("Flip Sequence:\n");
    for(int i=0;i<flipCount;i++){
        printf("%d ",flips[i]);
    }
    return 0;
}