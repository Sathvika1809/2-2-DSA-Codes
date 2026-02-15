#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int a1,b1,a2,b2;
    scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
    int sum = 0;
    for(int i=a1;i<=a2;i++){
        for(int j=b1;j<=b2;j++){
            sum+=arr[i][j];
        }
    }
    int P[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            P[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            P[i][j] = arr[i][j]+P[i-1][j]+P[i][j-1]-P[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",P[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%d\n",sum);

    return 0;
}