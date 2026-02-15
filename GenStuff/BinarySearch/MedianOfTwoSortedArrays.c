#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
float findMedian(int* arr1,int n1,int* arr2,int n2){
    if(n1>n2){
        return findMedian(arr2,n2,arr1,n1);
    }
    int n = n1+n2;
    int left = (n1+n2+1)/2;
    int lo = 0,hi = n1-1;
    int l1 =INT_MIN,l2=INT_MIN;
    int r1=INT_MAX,r2=INT_MAX;
    while(lo<=hi){
        int mid1 = lo+(hi-lo)/2;
        int mid2 = left-mid1;  
        int l1 =INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 =arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];
        
        if(l1<=r2&&l2<=r1){
            if(n%2==0){
                return (float)(max(l1,l2)+min(r1,r2))/2.0;
            }
            return (float)max(l1,l2);
        }   
        else if(l1>r2){
            hi = mid1-1;
        }else{
            lo = mid1+1;
        }
        }
        return 0;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr1[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    int arr2[m];
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    printf("%.2f",findMedian(arr1,n,arr2,m));

    return 0;
}