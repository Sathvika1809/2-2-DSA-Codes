#include <stdio.h>
#include <stdlib.h>
#include <climits.h>
#include <math.h>

int minElement(int a,int b){
    return a<b?a:b;
}
int maxElement(int a,int b){
    return a>b?a:b;
}
int maxdifference(int* nums,int n){
    if(n<2){
        return 0;
    }
    int maxdiff = 0;
    int min = nums[0];
    int max = nums[0];
    for(int i=0;i<n;i++){
        min = minElement(min,nums[i]);
        max = maxElement(max,nums[i]);
    }
    if(min == max){
        return 0;
    }
    int bucketsize = (int)ceil((double)(max-min)/(n-1));
    int bucketCount = n-1;
    int* bucketMin = (int*)malloc(sizeof(int));
    int* bucketMax = (int*)malloc(sizeof(int));
    for(int i=0;i<n;i++){
        bucketMin[i] = INT_MAX;
        bucketMax[i]=INT_MIN;
    }

}
int main(){
    int nums[]={3,6,9,1};
    int n = sizeof(nums)/sizeof(nums[0]);



}