#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int tgt;
    scanf("%d",&tgt);
    int i=0,j=n-1;
    int a=0;
    while(i<m&&j>=0){
        if(arr[i][j]==tgt){
            a=1;
            printf("True");
            break;
        }else if(arr[i][j]>tgt){
            j--;
        }else{
            i++;
        }
    }
    if(a==0){
        printf("false");
    }
return 0;
}