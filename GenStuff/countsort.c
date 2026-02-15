#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int outp[n];
    for(int k=0;k<n;k++){
        outp[k]=0;
    }
    int max = INT_MIN;
    for(int j=0;j<n;j++){
        if(arr[j]>max){
            max = arr[j];
        }
    }
    int cntArray[max+1];
    for(int i=0;i<max+1;i++){
        cntArray[i]=0;
    }
    for(int i=0;i<n;i++){
        cntArray[arr[i]]++;
    }
    for(int i=1;i<max+1;i++){
        cntArray[i]=cntArray[i]+cntArray[i-1];
    }
    for(int i=0;i<n;i++){
        outp[cntArray[arr[i]]-1] = arr[i];
        cntArray[arr[i]]--;//For Duplicates
    }
    for(int i=0;i<n;i++){
        printf("%d ",outp[i]);
    }

    return 0;
}