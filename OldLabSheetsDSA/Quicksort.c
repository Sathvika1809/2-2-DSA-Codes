#include <stdio.h>
void swap(int* arr,int left,int right){
    int temp = arr[left];
    arr[left]=arr[right];
    arr[right]=temp;
    return;
}
int partition(int* arr,int low,int high){
    int left = low;
    int right = high;
    int pivot_item = arr[low];
    while(left<right){
        while(arr[left]<=pivot_item && left<=high-1){
            left++;
        }while(arr[right]>=pivot_item && right>=low+1){
            right--;
        }
        if(left<right){
            swap(arr,left,right);
        }
    }
    arr[low]=arr[right];
    arr[right]=pivot_item;
    return right;
}
void quicksort(int* arr,int low,int high){
    int pivot=low;
    if(low<high){
        pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}