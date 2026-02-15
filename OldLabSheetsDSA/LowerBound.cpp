#include <iostream>
using namespace std;

int findLowerbound(int* arr,int n,int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
    
}
int main(){
int arr[] ={1,2,3,3,7,8,9,9,9,11};
int x =1;
int n = sizeof(arr)/sizeof(arr[0]);
printf("%d",findLowerbound(arr,n,x));
    return 0;
}