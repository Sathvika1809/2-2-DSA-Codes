#include <stdio.h>
#include <stdlib.h>

int maxElement(int* arr,int n){
    int max = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
void sortcount(int* arr,int n){
    int max = maxElement(arr,n);
    int* cntArr = (int*)calloc(max+1,sizeof(int));
    
    for(int i=0;i<n;i++){
        cntArr[arr[i]]++;
    }
    for(int j=1;j<max+1;j++){
        cntArr[j] = cntArr[j]+cntArr[j-1];
    }
   int* ans=(int*)malloc(n*sizeof(int));
   for(int i=n-1;i>=0;i--){
    ans[cntArr[arr[i]]-1] = arr[i];
       cntArr[arr[i]]--;
   }
   for(int i=0;i<n;i++){
     arr[i]=ans[i];
   }
   for(int i=0;i<n;i++){
    printf("%d",arr[i]);
   }
   free(cntArr);
   free(ans);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortcount(arr,n);
    return 0;
}