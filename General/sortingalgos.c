#include <stdio.h>
#include <stdlib.h>
void bubblesort(int* arr,int n);
void quicksort(int* arr,int n);
void printArr(int* arr,int n);
void swap(int* a,int* b);
int partition(int* arr,int st,int end);
void quicksortHelper(int* arr,int st,int end);
void insertionSort(int* arr,int n);
void selectionSort(int* arr,int n);

int main(){
    int n;
    scanf("%d",&n);
    int* arr =(int*)calloc(n,sizeof(int)); //Initialises all to 0
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);


    return 0;
}
void printArr(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;

}
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void selectionSort(int* arr,int n){
   for(int i=0;i<n;i++){
    int mini = arr[i];
    int minIdx = i;
    for(int j = i+1;j<n;j++){
        if(arr[j]<mini){
            mini = arr[j];
            minIdx = j;
        }
    }
    swap(&arr[i],&arr[minIdx]);
   }
   printArr(arr,n);
}

void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        int swapped = 0;
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                swap(&arr[j-1],&arr[j]);
                swapped =1;
            }
        }
        if(!swapped){
            break;
        }
    }
    printArr(arr,n);
}

void insertionSort(int* arr,int n){
    for(int i=0;i<n-1;i++){

        int j = i+1;
        int val = arr[j];
        while(j>0 && val<arr[j-1])
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
    return;
}
int partition(int* arr,int st,int end){
    int left = st;
    int right = end;
    int pivot = arr[end];
    while(left<right){
        while(left<right&&arr[left]<arr[right]){
            left++;
        }while(left<right&&arr[right]>arr[left]){
            right--;
        }
        if(left<right){
            swap(&arr[left],&arr[right]);
        }
    }
    swap(&arr[end],&arr[right]);
    return right;
}
void quicksortHelper(int* arr,int st,int end){

    if(st<end){
        int p = partition(arr,st,end);
        quicksortHelper(arr,st,p-1);
        quicksortHelper(arr,p+1,end);
    }
}
void quicksort(int* arr,int n){
    return quicksortHelper(arr,0,n-1);

}