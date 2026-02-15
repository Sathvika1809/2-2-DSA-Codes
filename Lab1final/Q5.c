#include <stdio.h>
void mergeArrays(int* A,int n1,int* B,int n2){
    int l=0,r=0,k=0;
    int n3 =n1+n2;
    int merge[n3];
    while(l<n1&&r<n2){
        if(A[l]<B[r]){
            merge[k++]=A[l];
            l++;
        }else if (A[l]==B[r]){
            merge[k++]=A[l];
            l++;
            r++;
        }else{
            merge[k++]=B[r];
            r++;
        }
    }
    while(l<n1){
        merge[k++]=A[l];
        l++;
    }
    while(r<n2){
        merge[k++]=B[r];
        r++;
    }
    for(int i=0;i<n3;i++){
        printf("%d ",merge[i]);
    }
    return;
}
int main(){
    int n1;
    scanf("%d",&n1);
    int A[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&A[i]);
    }
    int n2;
    scanf("%d",&n2);
    int B[n1];
    for(int i=0;i<n2;i++){
        scanf("%d",&B[i]);
    }
 mergeArrays(A,n1,B,n2);

}