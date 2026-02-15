#include <stdio.h>
#include <stdlib.h>
typedef struct Movie{
    int a;
    int b;
}Movie;
int max(int a,int b){
    return a>b?a:b;
}
int cmp(const void *a, const void *b) {
    Movie *m1 = (Movie *)a;
    Movie *m2 = (Movie *)b;

    if (m1->b < m2->b) return -1;
    if (m1->b > m2->b) return 1;
    return 0;
}
int maxMovies(Movie* m,int n){
    int cnt = 1;
    Movie last_end = m[0];
    for(int i=1;i<n;i++){
        if(m[i].a>=last_end.b){
            cnt++;
            last_end = m[i];
        }
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d",&n);
    Movie movies[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&movies[i].a,&movies[i].b);
    }
    qsort(movies,n,sizeof(struct Movie),cmp);
    printf("%d\n",maxMovies(movies,n));



    return 0;
}