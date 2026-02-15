#include <stdio.h>

void swap(int* a,int* b){
    int temp =*a;
    *a =*b;
    *b = temp;
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        int didSwap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                didSwap =1 ;
            }
        }
        if(!didSwap){
            break;
        }
    }
    return;
}
int main(){
     int n;
     printf("Enter the size : ");
     scanf("%d",&n);
     int arr[n];
     printf("Enter the elements of the array: ");
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
     bubblesort(arr,n);
     int i=0;
     while(i<n){
        int j=i+1;
        while(j<n&&arr[j]==arr[i]){
            j++;
        }
        printf("%d -> %d\n",arr[i],j-i);

        i=j;
     }

    return 0;
}