#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Pair_t{
    int val;
    int idx;
}Pair;
int comp(Pair p1,Pair p2){
     if(p1.val!=p2.val){
        return p1.val<p2.val;
    }
    return p1.idx<p2.idx;
}
void merge(Pair* arr,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
     Pair L[n1],R[n2];
     for(int i=0;i<n1;i++){
        L[i]=arr[i+l];
     }
     for(int j=0;j<n2;j++){
        R[j]=arr[j+m+1];
     }
     int i=0,j=0,k=l;
     while(i<n1&&j<n2){
        if(comp(L[i],R[j])){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
     }
     while(i<n1){
        arr[k++]=L[i++];
     }
     while(j<n2){
        arr[k++]=R[j++];
     }
     return;
}
void mergesort(Pair* a,int lo,int hi){
    if(lo<hi){
    int mid = lo+(hi-lo)/2;
    mergesort(a,lo,mid);
    mergesort(a,mid+1,hi);
    merge(a,lo,mid,hi);
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    Pair a[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[i].val=x;
        a[i].idx=i;
    }
    mergesort(a,0,n-1);
    int fnd=0;
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n&&a[j].val==a[i].val){
            if(abs(a[i].idx-a[j].idx)>k){
                printf("%d %d\n",a[i].idx,a[j].idx);
                fnd=1;
                break;
            }
            j++;
        }
        if(fnd){
            break;
        }
        i=j;
    }
    if(!fnd){
        printf("-1\n");
    }
    return 0;
}