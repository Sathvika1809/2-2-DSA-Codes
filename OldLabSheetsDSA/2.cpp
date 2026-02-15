#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
   int m,n,p,q;
   printf("Enter the values of m and n:");
   scanf("%d %d",&m,&n);
   int **A = malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++) {
    A[i] = malloc(n * sizeof(int));
}

 printf("Enter the values of p and q");
 scanf("%d %d",&p,&q);
 
 int **B = malloc(p * sizeof(int *));
 for(int i = 0; i < p; i++) {
    B[i] = malloc(q * sizeof(int));
}

 
 //Top left corner of B can only start
 //row = 0 to (N-n)
 //col = 0 to M-m
if((p < 0 || p>m-p)||(q < 0 || q > n-q)){
     printf("NO");
     return 0;
}


return 0;
}
bool checkSubMatrix(int m,int n,int A[m][n],int p,int q,int B[p][q]){
for(int i = 0;i<m;i++){
    for(int j = 0;j<n;j++){
        bool ok = true;
        if(A[i][j]==B[0][0]){
            if(i+p<=m &&j+q<=n){
            for(int l = i;l<i+p;l++){
            for(int k = j;k<j+q;k++){
                if(A[l][k]!=B[l-i][k-j]){
                    ok = false;
                    break;
                }
            }
        }
        }
        }
        else{
            continue;
        }
        if(ok){
            return true;
        }

    }
}
return false;
}





    