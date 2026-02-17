#include <stdio.h>
#include <stdlib.h>
typedef struct Pair_t{
    int val;
    int idx;
}pair;
int comp(pair p1,pair p2){
    if(p1.val!=p2.val){
        return p1.val<p2.val;
    }
    return p1.idx<p2.idx;
}
void merge(pair* arr,int lo,int mid,int hi){
   int n1 = mid-lo+1;
   int n2 = hi-mid;
   pair L[n1],R[n2];
   for(int i=0;i<n1;i++){
    L[i]=arr[lo+i];
   }
   for(int j=0;j<n2;j++){
    R[j]=arr[mid+1+j];
   }
   int i=0,j=0,k=lo;
   while(i<n1&&j<n2){
    if(comp(L[i],R[j])){
        arr[k++] = L[i++];
    }
    else{
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
void mergesort(pair* arr,int lo,int hi){
    if(lo<hi){
       int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
}
int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    pair* arr = malloc(n*sizeof(pair));
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        arr[i].val = val;
        arr[i].idx = i;
    }
    mergesort(arr,0,n-1);
    int i=0;
    int fnd=0;
    while(i<n){
        int j=i+1;
        while(j<n&&arr[j].val==arr[i].val){
            if(abs(arr[j].idx-arr[i].idx)>k){
                printf("%d %d\n",arr[i].idx,arr[j].idx);
                fnd=1;
                break;
            }
            j++;
        }
        if(fnd) break;
        i=j;
    }
    if(!fnd){
        printf("-1\n");
    }
    free(arr);
    return 0;

}