//Logic : Just Brute force checking every num from 1 if its present or not
//then if not present cnt to k then print it as it is kth missing number

#include <stdio.h>
#include <stdlib.h>
int present(int* arr,int n,int k,int curr){
    int lo = 0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==curr){
            return 1;
            break;
        }else if(arr[mid]<curr){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int curr=1;
    int cnt=0;
    while(1){
        if(present(arr,n,k,curr)){
            curr++;
        }else{
            cnt++;
            if(cnt==k){
                printf("%d\n",curr);
                break;
            }
            curr++;
        }
    }
    return 0;
}