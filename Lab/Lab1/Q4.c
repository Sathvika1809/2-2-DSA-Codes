#include <stdio.h>

void swap(int* a,int* b){
    int temp = *a;
    *a =*b;
    *b = temp;
}
void sortArrays(int* A,int n1){
    for(int i =0;i<n1;i++){
        int swapped = 0;
        for(int j = 0;j<n1-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}
void findUnion(int* A,int n1,int*B,int n2){
   int C[n1+n2];
   int n3 = n1+n2;
   for(int i = 0;i<n1+n2;i++){
    if(i<n1){
        C[i]=A[i];
    }else{
        C[i] = B[i-n1];
    }
   }
   sortArrays(C,n3);
   printf("Union: ");
   int i=0;
   while(i<n3){
    int j =i+1;
    while(j < n3 && C[j]==C[i]){
        j++;
    }
    printf("%d ",C[i]);
    i = j;
   }
    printf("\n");
}
void findIntersection(int* A,int n1,int* B,int n2){
   int i = 0,j=0;
   printf("Intersection: \n");
   while(i<n1&&j<n2){
    if(A[i]==B[j]){
        printf("%d ",A[i]);
        int curr = A[i];
        while(i<n1&&A[i]==curr)i++;
        while(j<n2&&B[j]==curr)j++;
    }else if(A[i]<B[j])i++;
    else j++;
   }
   printf("\n");
}
int main(){
    int n1;
    printf("Enter the Size of A: ");
    scanf("%d",&n1);
    int A[n1];
    printf("Enter the elements of First Array: ");
    for(int i = 0;i<n1;i++){
        scanf("%d",&A[i]);
    }
    int n2;
    printf("Enter the Size of B");
    scanf("%d",&n2);
    int B[n2];
    printf("Enter the elements of second Array: ");
    for(int i = 0;i<n2;i++){
        scanf("%d",&B[i]);
    }
    sortArrays(A,n1);
    sortArrays(B,n2);
    findUnion(A,n1,B,n2);
    printf("\n");
    findIntersection(A,n1,B,n2);
    return 0;
}