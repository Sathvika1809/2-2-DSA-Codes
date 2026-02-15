#include <iostream>
#include <climits>
using namespace std;
int findLargestSubarray(int* nums,int n){
    int sum = 0;
    int i=0;
    int maxi = INT_MIN;
    while(i<n){
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum = 0;
        }
        i++;
    }
    return maxi;
}

int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int sum = findLargestSubarray(nums,n);
    cout<<sum<<endl;

    return 0;
}