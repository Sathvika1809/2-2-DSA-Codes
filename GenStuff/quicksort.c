#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int partition(int* arr,int lo,int hi){
    int piv = arr[hi];
    int pivotIdx = hi;
    int i = lo-1;
    for(int j=lo;j<hi;j++){
        if(arr[j]<=piv){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[hi]);
    return i+1;
}
//Other way of partition from front
int partitionfront(int* arr,int lo,int hi){
    int piv = arr[lo];
    int left,right;
    int pivIdx = left = lo;
    int right = hi;
    while(left<right){
        if(arr[left]<=piv){
            left++;
        }else if(arr[right]>=piv){
            right--;
        }
        if(left<right){
            swap(&arr[left],&arr[right]);
        }
    }
    arr[low]=arr[right];
    arr[right]=piv;
    return right;
}
//Other way of partition from middle
int partitionmid(int* arr,int lo,int hi){
    int mid =lo+(hi-lo)/2;
    int piv = arr[mid];
    int pivIdx = mid;
    int left = lo;
    int right = hi;
    while(left<right){
        while(a[left]<=piv){
            left++;
        }while(a[right]>=piv){
            right--;
        }
        if(left<=right){
            swap(&arr[left],&arr[right]);
            left++;
            right--;
        }
    }
    return left;
}
void quicksortHelper(int* arr,int lo,int hi){
    if(lo<hi){
        int p=partition(arr,lo,hi);
        quicksortHelper(arr,lo,p-1);
        quicksortHelper(arr,p+1,hi);
    }
}
void quicksort(int* arr,int n){
    quicksortHelper(arr,0,n-1);
}
int main(){



    return 0;
}