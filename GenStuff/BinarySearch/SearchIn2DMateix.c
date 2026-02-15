#include <stdio.h>
#include <stdlib.h>
int binarySearch(int* mat,int m,int tgt){
    int lo = 0,hi = m-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(mat[mid]==tgt){
            return 1;
        }else if(mat[mid]>tgt){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return 0;
}
int findTarget(int n,int m,int mat[n][m],int tgt){
    for(int i=0;i<n;i++){
        if(mat[i][0]<=tgt && tgt<=mat[i][m-1]){
            return binarySearch(mat[i],m,tgt);
        }
    }
    return 0;
}
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int tgt;
    scanf("%d",&tgt);
    int a = findTarget(n,m,mat,tgt);
    if(a==1){
        printf("True");
    }else{
        printf("False");
    }


    return 0;
}