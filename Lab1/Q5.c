#include <stdio.h>

void mergeArray(int* arr1,int n1,int* arr2,int n2,int* merge,int n3){
    int k = 0;
    int left = 0;int right = 0;
    while(left<n1 && right<n2){
        if(arr1[left]<arr2[right]){
            merge[k++] = arr1[left];
            left++;
        }else if(arr1[left]>arr2[right]){
            merge[k++]= arr2[right];
            right++;
        }else{
            merge[k++]=arr1[left];
            left++;
            right++;
        }
    }
    while(left<n1){
        merge[k++]=arr1[left];
        left++;
    }
    while(right<n2){
        merge[k++]=arr2[right];
        right++;
    }
    for(int i = 0;i<n3;i++){
        printf("%d ",merge[i]);
    }
}
int main(){
    int n1;
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter the elements of Array 1:\n");
    for(int i = 0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    int n2;
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter the elements of Array 2:\n");
    for(int i =0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    int n3 = n1+n2;
    int merge[n3];
    mergeArray(arr1,n1,arr2,n2,merge,n3);
    
}