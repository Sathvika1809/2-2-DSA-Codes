#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the Key:\n");
    int tgt;
    scanf("%d",&tgt);
    int i=0,j=n-1;
    int fnd = 0;
    while(i<n&&j>=0){
        if(a[i][j]==tgt){
            printf("%d %d",i,j);
            fnd=1;
            break;
        }else if(a[i][j]<tgt){
            i++;
        }else{
            j--;
        }
    }
    if(!fnd){
        printf("-1\n");
    }
    return 0;
}