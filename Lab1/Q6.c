#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
    int c =*a;
    *a = *b;
    *b = c;
}
void bubblesort(int* arr,int n){
    for(int i = 0 ;i<n;i++){
        int swapped = 0;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return;
}
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i = 0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,N);
    int i =0;
    while(i<N){
        int j =i+1;
        while(j<N&& arr[j]==arr[i]){
            j++;
        }
        printf("%d -> %d\n",arr[i],j-i);
        i=j;
    }

    return 0;
}