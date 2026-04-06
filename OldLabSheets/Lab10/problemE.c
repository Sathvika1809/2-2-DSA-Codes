#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct Pair{
    int ff;
    int ss;
}Pair;
void merge(Pair* a,int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    Pair* L = (Pair*)malloc(n1*(sizeof(int)));
    Pair* R = (Pair*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++){
        L[i] = a[i+l];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[i+mid+1];
    }
    int i=0,j=0,k=0;
    while(i<n1&&j<n2){
        if(L[i].ff < R[j].ff || L[i].ff == R[j].ff && L[i].ss > R[j].ss){
            a[k++] = L[i++];
        }else{
            a[k++] = R[j++];
        }
    }
    while(i<n1){
        a[k++] = L[i++];
    }
    while(j<n2){
        a[k++] = R[j++];
    }
    free(L);
    free(R);
}
void mergesortHelper(int* arr,int l,int r){
    if(l<=r){
        int mid = l+(r-l)/2;
        mergesortHelper(a,l,mid);
        mergesortHelper(a,mid+1,r);
        merge(a,l,mid,r);
    }
    return;
}
void mergesort(int* arr,int n){
    mergesortHelper(arr,0,n-1);
}
int lower_bound(int* dp,int n,int val){
    int l=0,r=n;
    while(l<r){
        int mid = l+(r-l)/2;
        if(dp[mid]<key){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    return l;
}
//sort widths acc to mergesort and heights acc to bs
int main(){
    int n;
    scanf("%d",&n);
    Pair arr[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].ff,&arr[i].ss);
    }
    mergesort(arr,n);
    int* dp = (int*)malloc(sizeof(int));
    //smallest possible ending height of an increasing subsequence 
    //of length k+1
    int size = 0;
    for(int i=0;i<n;i++){
        int h = a[i].ss;
        int pos = lower_bound(dp,size,h);
        if(pos == size){
            dp[size++] = h;
        }else{
            dp[pos]= h;
        }
    }
    printf("%d\n",size);

    return 0;
}