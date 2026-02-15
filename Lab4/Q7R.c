#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int present(int* arr,int n,int curr){
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==curr){
            return 1;
        }else if(arr[mid]<curr){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return 0;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    int maxelem=INT_MIN;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int curr=1;
    int cnt=0;
    while(1){
        if(present(arr,n,curr)){
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