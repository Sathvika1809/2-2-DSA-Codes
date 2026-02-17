#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Memory{
    int start;
    int end;
}Memory;
void swap(Memory* m1,Memory* m2){
    Memory t =*m1;
    *m1=*m2;
    *m2=t;
}
int cmp(Memory m1,Memory m2){
    if(m1.start==m2.start){
        return m1.end<m2.end;
    }
    return m1.start<m2.start;
}

void bubble(Memory* m,int n){
    int swapped=0;
    do{
        swapped = 0;
        for(int j=0;j<n-1;j++){
            if(cmp(m[j+1],m[j])){
                swap(&m[j+1],&m[j]);
                swapped=1;
            }
        }
    }while(swapped==1);
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    Memory m[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&m[i].start,&m[i].end);
    }
    bubble(m,n);
    int conti=0;
    int Y = m[0].end;
    for(int i=1;i<n;i++){
        int xx = m[i].start;
        int yy = m[i].end;
        if(xx>Y){
            conti=1;
            break;
        }
        if(yy>Y){
            yy=Y;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %d",m[i].start,m[i].end);
        printf("\n");
    }
    if(conti==0){
        printf("Contiguous\n");
    }
    if(conti==1){
        printf("Fragmented\n");
    }



    return 0;
}