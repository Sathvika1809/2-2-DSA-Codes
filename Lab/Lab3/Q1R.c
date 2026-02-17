#include <stdio.h>
#include <stdlib.h>
typedef struct Student{
    int marks;
    int delay;
}Student;
void swap(Student* s1,Student* s2){
    Student temp =*s1;
    *s1 = *s2;
    *s2 = temp;
}
int cmp(Student* s1,Student* s2){
    if((*s1).marks>(*s2).marks){
        return 1;
    }else if((*s1).marks == (*s2).marks&&(*s1).delay<(*s2).delay){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Student students[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&students[i].marks,&students[i].delay);
    }
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            if(!cmp(&students[i],&students[j])){
                swap(&students[i],&students[j]);
            }
        }
    }
    printf("Printing\n");
    printf("\n \n");
    for(int i=0;i<n;i++){
        printf("%d %d\n",students[i].marks,students[i].delay);
    }
return 0;
}