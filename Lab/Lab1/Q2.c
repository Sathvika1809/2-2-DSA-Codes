#include <stdio.h>
void matrixMultiplication(int r1,int c1,int A[r1][c1],int r2,int c2,int B[r2][c2]){
    if(c1 != r2){
        printf("Not possible");
        return;
    }
    int C[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            C[i][j] = 0;
            for(int k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int r1,c1,r2,c2;
    printf("Enter the no.of rows and cols of matrix A: ");
    scanf("%d",&r1);
    scanf("%d",&c1);
    int A[r1][c1];
    printf("Enter the elements of matrix A: ");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the no.of rows and cols of matrix B: ");
    scanf("%d",&r2);
    scanf("%d",&c2);
    int B[r2][c2];
    printf("Enter the elements of matrix B: ");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&B[i][j]);
        }
    }
    matrixMultiplication(r1,c1,A,r2,c2,B);
    return 0;

}