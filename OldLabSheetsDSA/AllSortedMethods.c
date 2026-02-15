#include <stdio.h>
#include <stdlib.h>

void selectionsort(int* arr,int n);
void bubblesort(int* arr,int n);
void insertionsort(int* arr,int n);
void mergesort(int* arr,int low,int high);
void printList(int* arr,int n);
void merge(int* arr,int low,int mid,int high);
// void quicksort(int* arr,int n);
// void heapsort(int* arr,int n);
void printList(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int* arr,int n){
    for(int i = 0;i<n;i++){
        int didSwap=0;
        int mini = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
                didSwap = 1;
            }
        }
        swap(&arr[i],&arr[mini]);
        if(!didSwap){
            break;
        }
    }
}
void bubblesort(int* arr,int n){
    for(int i = 0;i<n-1;i++){
        int didSwap = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            swap(&arr[j+1],&arr[j]);
            didSwap = 1;
            }
        }
        if(!didSwap){
            break;
        }
    }

}
void insertionsort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int j = i+1; 
        int val = arr[j]; 
        while(j>0 && val<arr[j-1]){
            arr[j] = arr[j-1]; 
            j--;
        }
        arr[j] = val;
    }
    return;
}
void mergesort(int* arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid = low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void merge(int* arr,int low,int mid,int high){
    int* temp = calloc(1000,sizeof(int));
    int k=0;
    int left = low;
    int right = mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<arr[right]){
            temp[k]=arr[left];
            left++;
        }else if(arr[right]<arr[left]){
            temp[k]=arr[right];
            right++;
        }else{
            temp[k]=arr[left];
            left++;
            right++;
        }
        k++;
    }
    while(left<=mid){
        temp[k++]=arr[left];
        left++;
    }
    while(right<=high){
        temp[k++]=arr[right];
        right++;
    }
    for(int i=0;i<k;i++){
        arr[low+i]=temp[i];
    }
}
int main(){
    int n;
    printf("Enter the size of the Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Sorting using selection sort: ");
    selectionsort(arr,n);
    printList(arr,n);
    printf("Sorting using bubble sort: ");
    bubblesort(arr,n);
    printList(arr,n);
    printf("Sorting using insertion sort: ");
    insertionsort(arr,n);
    printList(arr,n);
    printf("Sorting using mergesort: ");
    mergesort(arr,0,n-1);
    printList(arr,n);
}