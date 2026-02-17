#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Memory{
    int start;
    int end;
}Memory;

void printList(Memory* m,int n){
    for(int i=0;i<n;i++){
        printf("%d %d",m[i].start,m[i].end);
        printf("\n");
    }
}
void swap(Memory* m1,Memory* m2){
    Memory t =*m1;
    *m1 = *m2;
    *m2 = t;
}
int cmp(Memory m1,Memory m2){
    if(m1.start>m2.start){
        return 1;
    }else if(m1.start==m2.start&&m1.end>m2.end){
        return 1;
    }else{
        return 0;
    }
}
void bubblesort(Memory* m,int n){
    for(int i=0;i<n;i++){
       int swapped= 0;
        for(int j=0;j<n-i-1;j++){
            if(cmp(m[j],m[j+1])){
                swap(&m[j],&m[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Memory memory[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&memory[i].start,&memory[i].end);
    }
    bubblesort(memory,n);
    int conti = 1;
    int Y = memory[0].end;
    for(int i=1;i<=n;i++){
        int xx = memory[i].start;
        int yy = memory[i].end;
        if(xx>Y){
            conti = 0;
            break;
        }
        if(yy>Y){
            Y = yy;
        }
    }
    printList(memory,n);
    if(conti){
        printf("Contiguous\n");
    }else{
        printf("Fragmented\n");
    }
    return 0;
}