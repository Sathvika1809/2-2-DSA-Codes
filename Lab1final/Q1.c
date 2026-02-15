#include <stdio.h>
#include <stdlib.h>
typedef struct Student{
    int id;
    char name[1000];
    float marks[3];
}Student;
int main(){
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    Student students[n];
    float maxAv = 0;
    for(int i=0;i<n;i++){
        printf("Enter the %d student id",i+1);
        scanf("%d",&students[i].id);
        printf("Enter the %d student name: ",i+1);
        scanf("%s",students[i].name);
        printf("Enter the %d student marks: ",i+1);
        float tot=0;
        for(int j=0;j<3;j++){
            scanf("%f",&students[i].marks[j]);
            tot+=students[i].marks[j];
        }
        tot=tot/3;
        if(maxAv<tot){
             maxAv = tot;
        }
        }
        printf("Merit List\n");
        for(int i=0;i<n;i++){
            float avg =0;
            for(int j=0;j<3;j++){
                avg+=students[i].marks[j];
            }
            avg/=3;
            if(avg>75){
                printf("%d %s ",students[i].id,students[i].name);
            }
        }
        printf("\n");
        printf("Topper:\n");
        for(int i=0;i<n;i++){
            float avg = 0;
            for(int j=0;j<3;j++){
                avg+=students[i].marks[j];
            }
            avg/=3;
            if(avg == maxAv){
                printf(" %s",students[i].name);
            }
        }

        return 0;
}