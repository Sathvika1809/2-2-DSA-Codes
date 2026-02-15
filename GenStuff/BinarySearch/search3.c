#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int tgt;
    scanf("%d",&tgt);
    int i=0,j=m-1;
    int a=0;
    while(i<n&&j>=0){
        if(mat[i][j]==tgt){
            printf("%d %d",i,j);
            a=1;
            break;
        }else if(mat[i][j]>tgt){
            j--;
        }else{
            i++;
        }
    }
    if(a==0){
        printf("Not Found!");
    }
    return 0;
}