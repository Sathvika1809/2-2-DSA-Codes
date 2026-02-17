#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b = temp;
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int findelements(int* arr,int l,int r,int tgt){
    int ans = r+1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]>tgt){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return ans;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int k;
    printf("Enter the maximum difference you want: ");
    scanf("%d",&k);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    int ans=0;
    for(int i=0;i<n;i++){
        // int j = findelements(arr,i,n-1,arr[i]+k);
        // ans = max(ans,j-i);
        for(int j=i+1;j<n;j++){
            int fnd =0;
            if(arr[j]>arr[i]+k){
                ans = max(ans,j-i);
                fnd = 1;
                break;
            }
        }
        if(!fnd){
            ans = max(ans,n-i);
        }
    }
    printf("%d ",ans);
    return 0;
}