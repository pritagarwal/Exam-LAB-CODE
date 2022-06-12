#include <stdbool.h>
#include <stdio.h>
 

#define V 4
int f =0;
 
void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[])
{

    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
 
 void  graphColoring(bool graph[V][V], int m, int i,
                   int color[V])
{
    
    if (i == V) {
       
        if (isSafe(graph, color)) {
            f=1;
            printSolution(color);
        }
        return ;
    }
 
   
    for (int j = 1; j <= m; j++) {
         color[i] = j;
         graphColoring(graph, m, i + 1, color);
         color[i] = 0;
        
    }
}
 

void printSolution(int color[])
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %c-->%d \n",i+65, color[i]);
    printf("\n");
}
 

int main()
{

    bool graph[V][V] = {
        { 0, 1, 1, 0 },
        { 1, 0, 0, 1 },
        { 1, 0, 0, 1 },
        { 0, 1, 1, 0 },
    };
    int m = 4; // Number of colors
 
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
      graphColoring(graph, m, 0, color);
      if(f ==0)
       printf("Solution does not exist");
 
    return 0;
}