#include <stdio.h>
// int countInversions(int* arr,int n){
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//        for(int j=i+1;j<n;j++){
//          if(arr[i]>arr[j]){
//             cnt++;
//          }
//        }
//     }
//     return cnt;
    
// }O(n^2) - not asked mthd in que
void merge(int* arr,int low,int mid,int high,int* ans){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1];
    int R[n2];
    for(int i=low;i<=mid;i++){
        L[i-low] = arr[i];
    }
    for(int i=mid+1;i<=high;i++){
        R[i-mid-1]=arr[i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }else{
            *ans += (mid-low+1-i);
            arr[k++]=R[j++];
        }
    }
    while(i<mid-low+1){
        arr[k++]=L[i++];
    }
    while(j<high-mid){
        arr[k++]=R[j++];
    }
}
void mergesort(int* arr,int low,int high,int* ans){
    if(low<high){
        int mid = low+(high-low)/2;
        mergesort(arr,low,mid,ans);
        mergesort(arr,mid+1,high,ans);
        merge(arr,low,mid,high,ans);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int ans = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1,&ans);
    printf("%d\n",ans);


    return 0;
}