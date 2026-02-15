#include <stdio.h>
#include <stdbool.h>
void checkSubsetSum(int* arr,int n,int s,int i,int *idxs,int k,int sum,bool* done){
    if(sum == s){
        printf("POSSIBLE\n");
        for(int x=0;x<k;x++){
            printf("%d",idxs[x]);
        }
        printf("\n");
        *done = true;
        return;
    }
    if(*done || i>=n ||sum>s){
        return;
    }
    //not take
    checkSubsetSum(arr,n,s,i+1,idxs,k,sum,done);
    //take
    idxs[k]=i;
    checkSubsetSum(arr,n,s,i+1,idxs,k+1,sum+arr[i],done);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int s;
    scanf("%d",&s);
    int idxs[n];
    bool done = false;
    checkSubsetSum(arr,n,s,0,idxs,0,0,&done);
    if(!done){
        printf("Not possible\n");
    }
    return 0;
}