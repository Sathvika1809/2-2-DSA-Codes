#include <stdio.h>
#include <stdlib.h>
typedef struct Data{
    int marks;
    int delay;
}Data;
void swap(Data* d1,Data* d2){
    Data temp = *d1;
    *d1=*d2;
    *d2 = temp;
}
int compare(Data d1,Data d2){
    if(d1.marks>d2.marks){
        return 1;
    }
    if(d1.marks == d2.marks && d1.delay< d2.delay){
        return 1;
    }
    return 0;
}
void bubble(Data* d,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            int a = compare(d[j],d[j+1]);
            if(a){
                swap(&d[j],&d[j+1]);
            }
        }
    }
}
void reverseList(Data* d,int n){
    for(int i=0;i<n/2;i++){
        Data temp = d[i];
        d[i]=d[n-i-1];
        d[n-i-1] = temp;
    }
}
void printList(Data* d,int n){
    printf("Output: \n");
    for(int i=0;i<n;i++){
        printf("%d %d",d[i].marks,d[i].delay);
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Data d[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&d[i].marks,&d[i].delay);
    }
    bubble(d,n);
    reverseList(d,n);
    printList(d,n);


    return 0;
}
