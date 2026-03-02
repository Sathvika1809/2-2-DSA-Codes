#include <stdio.h>
#include <stdlib.h>
void bubblesort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapped = 1;
            }
        }
        if(!swapped)break;
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    int fnd=0;
    for(int i=0;i<n-2;i++){
        if(i>0 && a[i]==a[i-1])continue;
         int j=i+1;
         int k=n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum==0){
                printf("%d %d %d\n",a[i],a[j],a[k]);
                fnd=1;
                while(j<k &&a[j]==a[j+1])j++;
                while(j<k && a[k]==a[k-1])k--;
                j++;
                k--;
            }
            else if(sum>0){
                k--;
            }else{
                j++;
            }
        }
    }
    if(!fnd){
        printf("No triplets Found\n");
    }
    return 0;
}