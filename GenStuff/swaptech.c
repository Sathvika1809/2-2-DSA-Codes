#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    *a =*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void swap2(int* a,int* b){
    *a =*a+*b;
    *b =*a-*b;
    *a = *a-*b;

}
void swap3(int* a,int* b){
    int t =*a;
    *a=*b;
    *b = t;
}
int main(){
    int a=5;
    int b=6;
    swap3(&a,&b);
    printf("%d %d",a,b);


    return 0;
}