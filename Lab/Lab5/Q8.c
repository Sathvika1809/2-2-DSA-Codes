#include <stdio.h>
#include <stdlib.h>
typedef struct Interval{
    int start;
    int end;
}Interval;
void swap(Interval* arr1,Interval* arr2){
    Interval temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
Interval merge(Interval arr,Interval yy){
    Interval newList;
    newList.start = arr.start<yy.start?arr.start:yy.start;
    newList.end = arr.end>yy.end?arr.end:yy.end;
    return newList;
}
int cmp(Interval arr1,Interval arr2){
    if(arr1.end<=arr2.start){
        return 1;
    }
    return 0;
}
void sort(Interval* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(cmp(arr[j+1],arr[j])){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Interval arr[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].start,&arr[i].end);
    }
    sort(arr,n);
    Interval* newArr = (Interval*)malloc(n*sizeof(Interval));
    Interval current = arr[0];
    int k=0;
    for(int i=1;i<n;i++){
        if(arr[i].start<=current.end){
          current = merge(current,arr[i]);
        }else{
            newArr[k++]=current;
            current = arr[i];
        }  
    }
    newArr[k++]=current;
    for(int i=0;i<k;i++){
        printf("%d %d",newArr[i].start,newArr[i].end);
        printf("\n");
    }
    free(newArr);
    
    return 0;
}