#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
    int temp = *a;
    *a =*b;
    *b = temp;
}
void bubblesort(int* a,int n){
    for(int i =0;i<n;i++){
        int didSwap =0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                didSwap = 1;
            }
        }
        if(!didSwap){
            break;
        }
    }
}
int main(){
    int n;
    printf("Enter the size of A: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of A: ");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int B[n+2];
    printf("Enter the elements of B: ");
    for(int i=0;i<n+2;i++){
        scanf("%d",&B[i]);
    }
    bubblesort(A,n);
    bubblesort(B,n+2);
    int left = 0;
    int right = 0;
    while(left<n&&right<n+2){
        if(A[left]!=B[right]){
            printf("%d ",B[right++]);
        }
         else{
            left++;
            right++;
        }
    }
    while(right<n+2){
        printf("%d ",B[right++]);
    }
    printf("\n");
    return 0;
}
