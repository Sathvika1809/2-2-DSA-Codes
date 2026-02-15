#include <stdio.h>
#include <stdlib.h>
void threeSum(int* a,int n){
    int l=0,r=n-1;
    int fnd = 0;
    for(int i=0;i<n-2;i++){
        if(i>0 && a[i]==a[i-1])continue;
        l=i+1;
        r=n-1;
        while(l<r){
            int sum = a[i]+a[l]+a[r];
            if(sum == 0){
            int fnd = 1;
            printf("%d %d %d",a[i],a[l],a[r]);
            while(l<r && a[l]==a[l+1]) l++;
            while(l<r && a[r]==a[r-1])r--;
            l++;
            r--;
        }else if(sum>0){
            r--;
        }else{
            l++;
        }
    }
}
if(!fnd){
    printf("No triplets Found!\n");
}
return;
}
void bubble(int* arr,int n){
    for(int i=0;i<n;i++){
        int found = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                found = 1;
            }
        }
        if(!found){
            break;
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble(arr,n);
    threeSum(arr,n);
    return 0;
}