#include <stdio.h>

void multiplyMatrices(int r1,int c1,int A[r1][c1],int r2,int c2,int B[r2][c2]){
    if(c1!=r2){
        printf("Not Possible");
        return;
    }
    int C[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<r2;j++){
            C[i][j]=0;
            for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d",C[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int r1,c1,r2,c2;
    printf("Enter the rows and columns of first matrix: ");
    scanf("%d",&r1);
    scanf("%d",&c1);
    int A[r1][c1];
    printf("Enter the elements of first matrix: ");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the rows and columns of second matrix: ");
    scanf("%d",&r2);
    scanf("%d",&c2);
    int B[r2][c2];
    printf("Enter the elements of second matrix: ");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&B[i][j]);
        }
    }
    multiplyMatrices(r1,c1,A,r2,c2,B);
    return 0;

}
