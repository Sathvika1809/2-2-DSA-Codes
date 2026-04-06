#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

int max(int a,int b){
    return a>b?a:b;
}
int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int maxCrossing(int* a,int l,int mid,int r){
    
    //First calculate left suffix sum
    int sum = 0;
    int ans = INT_MIN;
    for(int i=mid;i>=l;i--){
        sum+=a[i];
        ans = max(ans,sum);
    }
    int leftAns = ans;
    sum = 0;
    ans =INT_MIN;
    for(int i=mid+1;i<=r;i++){
        sum+=a[i];
        ans = max(ans,sum);
    }
    int rightAns = ans;
    return leftAns+rightAns;

}
int maxSubArraySum(int* a,int l,int r){

    if(l==r)return a[l];
    int mid = (l+r)/2;
    int leftAns = maxSubArraySum(a,l,mid);
    int rightAns = maxSubArraySum(a,mid+1,r);
    int crossingSum = maxCrossing(a,l,mid,r);

    return max3(leftAns,rightAns,crossingSum);

}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = maxSubArraySum(a,0,n-1);
    printf("%d\n",ans);
    return 0;
}





/* Kadane Algorithm TC:O(n)
int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum = a[0];
    int ans = a[0];
    for(int i=1;i<n;i++){
        sum = max(a[i],sum+a[i]); //rep the sum should restart or continue
        ans = max(ans,sum);//rep the best sum
    }
    printf("%d\n",ans);


    return 0;

*/