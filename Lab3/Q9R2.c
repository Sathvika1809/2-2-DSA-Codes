#include <stdio.h>
#include <stdlib.h>
void merge(int* arr,int l,int m,int r,int* ans){
    int lsz = m-l+1,rsz = r-m;
    int* left =(int*)calloc(lsz,sizeof(int));
    int* right = (int*)calloc(rsz,sizeof(int));
    for(int i=l;i<=r;i++){
        if(i<=m){
            left[i-l]=arr[i];
        }else{
            right[i-m-1]=arr[i];
        }
    }
    int i=0,j=0,k=l;
    while(i<lsz&&j<rsz){
        if(left[i]<right[j]){
            arr[k] = left[i++];
        }else if(left[i]>right[j]){
            *ans +=(lsz-i);
            arr[k] = right[j++];
        }
        k++;
    }
    while(i<lsz){
        arr[k++]=left[i++];
    }
    while(j<rsz){
        arr[k++]=right[j++];
    }
    free(left);
    free(right);
    return ;
}
void mergesort(int* arr,int lo,int hi,int* ans){
    if(lo<hi){
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid,ans);
        mergesort(arr,mid+1,hi,ans);
        merge(arr,lo,mid,hi,ans);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = 0;
    mergesort(arr,0,n-1,&ans);
    printf("%d\n",ans);

    return 0;
}
