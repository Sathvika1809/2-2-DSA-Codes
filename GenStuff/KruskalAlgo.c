#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u;
    int v;
    int w;
}Edge;

typedef struct{
    int parent;
    int rank;
}DSU;
DSU* dsu;
// Make-Set
void make_set(int n) {

dsu = (DSU *)malloc((n + 1) * sizeof(DSU));

for (int i = 1; i <= n; i++) {
        dsu[i].parent = i;
        dsu[i].rank = 0;
    }
}
// Find-Set with path compression
int find_set(int x) {
if (dsu[x].parent != x){
dsu[x].parent = find_set(dsu[x].parent);
}
return dsu[x].parent;
}
// Union by rank
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){
        if(dsu[a].rank<dsu[b].rank){
            dsu[a].parent = b;
        }else if(dsu[a].rank > dsu[b].rank){
            dsu[b].parent = a;
        }else{
            dsu[b].parent = a;
            dsu[a].rank++;
        }
    }
}
//Comparison fn for sorting edges
int cmp(const void *a,const void *b){
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->w - e2->w;
}
int main(){
    int V,E;
    scanf("%d",&V);
    scanf("%d",&E);
    Edge edges[E];
    //Read Edges
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }
    // Initialize DSU
    make_set(V);
    qsort(edges,E,sizeof(Edge),cmp);
    int mst_cost = 0;
    int edges_used = 0;
    printf("Edges in the MST:\n");
    //Kruskal Algorithm
    for(int i=0;i<E;i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find_set(u) != find_set(v)){
            printf("%d -- %d(weight = %d)\n",u,v,w);
            mst_cost+=w;
            edges_used++;
            union_sets(u,v);

            if(edges_used == V-1){
                break;
            }
        }
    }
    printf("Total Cost of MST = %d\n",mst_cost);
    free(dsu);
    return 0;
}