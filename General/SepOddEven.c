//TC = O(N) two ptr mthd as it requires to
//traverse the array atleast once because
//u have to see the element even or odd
//SC=O(1) other than input


#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int l=0,r=n-1;
    while(l<=r){
        if(arr[l]%2==0){
            l++;
        }else if(arr[r]%2==1){
            r--;
        }else{
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");



    return 0;
}