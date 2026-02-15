#include <stdio.h>

int maxElement(int a,int b){
    return a>b?a:b;
}
int rotatemax(int* arr,int n){
    int sum=0;
    int F=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        F+=i*arr[i];
    }
    int maxVal = F;
    for(int k=1;k<n;k++){
      F+=sum-n*arr[n-k];
      maxVal = maxElement(maxVal,F);
    }
    return maxVal;
}
int main(){
    int nums[] = {4, 3, 2, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", rotatemax(nums, n));
    return 0;
}