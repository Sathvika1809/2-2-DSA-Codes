#include <stdio.h>
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int max(int a,int b){
    return a>b?a:b;
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        int didSwap = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                didSwap = 1;
            }
        }
        if(!didSwap){
            break;
        }
    }
    return;
}
int findminmax(int* arr,int n,int k){
    bubblesort(arr,n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int fnd = 0;
       for(int j=i+1;j<n;j++){
            if(arr[j]>k+arr[i]){
                fnd = 1;
                ans = max(ans,j-i);
                break;
            }
       }
       if(!fnd){
            ans = max(ans,n-i);
       }
   }
   return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Enter k: ");
    int k;
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",findminmax(arr,n,k));
}