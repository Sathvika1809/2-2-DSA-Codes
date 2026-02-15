#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int findMaxElement(int n,int m,int arr[n][m],int mid){
    int max = INT_MIN;
    int rowIdx=0;
    for(int i=0;i<n;i++){
        if(arr[i][mid]>max){
            max = arr[i][mid];
            rowIdx = i;
        }
    }
    return rowIdx;
}
void findPeak(int n,int m,int arr[n][m]){
    int res[2];
    for(int i=0;i<2;i++){
        res[i]=-1;
    }
    int lo=0,hi=m-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int row = findMaxElement(n,m,arr,mid);
        int left = mid-1>=0?arr[row][mid-1]:INT_MIN;
        int right = mid+1<m?arr[row][mid+1]:INT_MIN;
        if(arr[row][mid]>left&&arr[row][mid]>right){
            res[0] = row;
            res[1] = mid;
            break;
        }else if(left>arr[row][mid]){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    for(int i=0;i<2;i++){
        printf("%d ",res[i]);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    findPeak(n,m,arr);
    
    return 0;
}