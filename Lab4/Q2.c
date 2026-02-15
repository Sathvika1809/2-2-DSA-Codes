#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
    return a<b?a:b;
}
void bubblesort(int* arr,int left,int right){
    for(int i=left;i<=right;i++){
        int fnd =0;
        for(int j=left;j<right-(i-left);j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                fnd = 1;
            }
        }
        if(!fnd){
            break;
        }
    }
    return;
}
void findIncreasingSize(int* arr,int n){
    int left = 0;
    int right = n-1;
    int k=1;
    int size=0;
    int takeFromFront=1;
    while(left<=right){
        size = min(k,right-left+1);
        if(takeFromFront){
            bubblesort(arr,left,left+size-1);
            left+=size;
        }else{
            bubblesort(arr,right-size+1,right);
            right-=size;
        }
        takeFromFront = !takeFromFront;
        k++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findIncreasingSize(arr,n);
    

    return 0;
}