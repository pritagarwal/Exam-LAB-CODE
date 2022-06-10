/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#define INF 9999



struct  edge{
    int u;
    int v;
    int w;
};

struct graph{
    int tv;
    int te;
    struct edge *edge;
};

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bell(struct graph *g,int s){
    int i,j,u,v,w;
    
    int te = g->te;
    int tv = g->tv;
    int d[tv];
    int p[te];
    
    for(int i=0;i<tv;i++){
        d[i] = INF;
        p[i] = 0;
    }
    
    d[0]= 0;
    
    for(i=1;i<=tv-1;i++){
        for(j=0;j<te;j++){
            
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            if(d[u] != INF && d[v]>d[u]+w){
                p[v] = u;
                d[v] =d[u]+w;
            }
        }
    }
    
    printf("\nDistance array:-");
    display(d,tv);
    printf("\nPredecessor array:-");
    for(int i=1;i<tv;i++){
        if(p[i] == 0){
            printf("\nS-->%c",(64+i));
        }
        else
         printf("\n%c-->%c",(64+p[i]),(64+i));
        
    }

    
}

int main()
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    
    g->tv=6;
    g->te=8;
    g->edge = (struct edge*)malloc(g->te * sizeof(struct edge));
    for(int i=0;i<8;i++){
        printf("enter (%d) u v w : ",(i+1));
        scanf("%d %d %d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);
    }
    
    bell(g,0);
    return 0;
}
