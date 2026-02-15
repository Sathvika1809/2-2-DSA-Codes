#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cmp(int a,int b){
    int acpy=a,bcpy=b;
    int cnt1=0,cnt2=0;
    while(a){
        cnt1+=(a%2==1);
        a/=2;
    }
    while(b){
        cnt2+=(b%2==1);
        b/=2;
    }
    if(cnt1!=cnt2)return cnt1>cnt2;
    return acpy>bcpy;
}
void bubble(int* a,int n){
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(cmp(a[j+1],a[j])){
                int t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
                swapped =1;
            }
        }
        if(!swapped){
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
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}