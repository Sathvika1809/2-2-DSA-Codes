#include <stdio.h>
void reverse(int* arr,int l,int r){
   while(l<r){
    int temp = arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
    l++;
    r--;
   }
    
}
int rotatefuncn(int* arr,int n){
    int F=0;
    for(int i=0;i<n;i++){
        F+=i*arr[i];
    }
    return F;
}
int maxElement(int a,int b){
    return a>b?a:b;
}
int rotatemax(int* arr,int n){
    int temp[n];
    int max =0;
    for(int k=1;k<n;k++){
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    reverse(temp,0,k-1);
    reverse(temp,k,n-1);
    reverse(temp,0,n-1);
    int d = rotatefuncn(temp,n);
    max = maxElement(max,d);
    }
    return max;

}
int main(){
    int nums[] = {4,3,2,6};
    int n = sizeof(nums)/sizeof(nums[0]);
    printf("%d",rotatemax(nums,n));

}