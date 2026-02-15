#include <stdio.h>
void swap(int* a,int* b){
    int temp =*a;
    *a =*b;
    *b = temp;
    return;
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        int didSwap = 0;
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
            swap(&arr[j],&arr[j+1]);
            didSwap = 1;
            }
        }
    if(!didSwap){
        break;
    }
}
return;
}
void findUnion(int* A,int n1,int* B,int n2){
    int n3 = n1+n2;
    int i=0;
    int C[n3];
    while(i<n3){
        if(i<n1){
            C[i] = A[i];
        }else{
            C[i]=B[i-n1];
        }
        i++;
    }
    bubblesort(C,n3);
    printf("Union: ");
    i=0;
    while(i<n3){
        int j = i+1;
        while(j<n3 && C[j]==C[i]) {
            j++;
        }
        printf("%d ",C[i]);
        i=j;
    }
    return;
}
void findIntersection(int* A,int n1,int* B,int n2){
    printf("Intersection: ");
    int i=0,j=0;
    while(i<n1&&j<n2){
            if(A[i]==B[j]){
                printf("%d ",A[i]);
                int curr = A[i];
                while(i<n1&&curr==A[i])i++;
                while(j<n2&&curr==B[j])j++;
            }else if(A[i]<B[j])i++;
            else j++;
        }
        printf("\n");
    return;
}
int main(){
    int n1;
    printf("Enter the size of A: ");
    scanf("%d",&n1);
    int A[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&A[i]);
    }
    int n2;
    printf("Enter the size of B: ");
    scanf("%d",&n2);
    int B[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&B[i]);
    }
    bubblesort(A,n1);
    bubblesort(B,n2);
    findUnion(A,n1,B,n2);
    findIntersection(A,n1,B,n2);



}
