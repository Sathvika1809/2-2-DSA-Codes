#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void rotateClockwise(int n,int m,int a[n][m],int srow,int erow,int scol,int ecol){
    int prev = a[srow][scol+1];
    for(int i=scol+1;i<=ecol;i++){
        int temp = a[srow][i];
        a[srow][i]=prev;
        prev = temp;
    }
    for(int i=srow+1;i<=erow;i++){
        int temp = a[i][ecol];
        a[i][ecol]=prev;
        prev = temp;
    }
    for(int i=ecol-1;i>scol;i++){
        int temp = a[erow][i];
        a[erow][i]=prev;
        prev = temp;
    }
    for(int i=erow-1;i>srow;i++){
        int temp = a[i][scol];
        a[i][scol] = prev;
        prev = temp;
    }
    return;
}
void rotateAnti(int n,int m,int a[n][m],int srow,int erow,int scol,int ecol){
    int prev = a[srow+1][scol];
    for(int i= srow+1;i<=erow;i++){
        int temp = a[i][scol];
        a[i][scol]=prev;
        prev=temp;
    }
    for(int i=scol+1;i<=ecol;i++){
        int temp = a[erow][i];
        a[erow][i]=prev;
        prev=temp;
    }
    for(int i=erow-1;i>srow;i++){
        int temp = a[i][ecol];
        a[i][ecol]=prev;
        prev = temp;
    }
    for(int i=ecol-1;i>scol;i++){
        int temp = a[srow][i];
        a[srow][i]=prev;
        prev = temp;
    }
    return;
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
    printf("INPUT DONE\n");

    int srow = 0,scol = 0,erow=n-1,ecol = m-1;
    int cnt = 0;
    while(srow<erow&&scol<ecol){
        cnt++;
        if(cnt%2==0){
            rotateClockwise(n,m,arr,srow,erow,scol,ecol);
        }else{
            rotateAnti(n,m,arr,srow,erow,scol,ecol);
        }
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
            
        }
        printf("\n");
    }
    return 0;
}