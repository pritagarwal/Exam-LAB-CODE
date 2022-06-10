/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define max 100
   int g[][6] ={
       {0,7,0,8,0,0},
       {7,0,6,3,0,0},
       {0,6,0,4,2,5},
       {8,3,4,0,3,0},
       {0,0,2,3,0,2},
       {0,0,5,0,2,0}
   };
   
   
   typedef struct edge{
     int u;
     int v;
     int w;
   }edge;
   
   typedef struct elist{
     edge arr[max];  
     int n;
   }elist;
   
   elist Edge;
   elist mst;
   
   
   void display(elist edge){
       
       printf("\n%10s %10s %10s","Source","Desti","Weight");
       for(int i=0;i<edge.n;i++){
           printf("\n\t%c\t%c\t%d",edge.arr[i].u+65,edge.arr[i].v+65,edge.arr[i].w);
       }
   }
   int find(int p[],int v){
       return p[v];
   }
   void  union1(int p[],int u,int v){
       for(int i=0;i<6;i++){
           if(p[i] == v){
               p[i] = u;
           }
       }
   }
   

   
int main()
{
   int p[6];
   for(int i=1;i<6;i++){
       for(int j=0;j<i;j++){
           if(g[i][j]!=0){
               Edge.arr[Edge.n].u=i;
               Edge.arr[Edge.n].v=j;
               Edge.arr[Edge.n].w =g[i][j];
               Edge.n++;
           }
       }
   }
   printf("\nBefore:-\n");
   display(Edge);
     
       edge t;
       int n = Edge.n;
       for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(Edge.arr[j].w>Edge.arr[j+1].w){
                   t = Edge.arr[j];
                   Edge.arr[j] = Edge.arr[j+1];
                   Edge.arr[j+1] = t;
                    
               }
              
           }
       }
  printf("\nAfter:-\n");
  display(Edge);
  
  for(int i=0;i<6;i++){
      p[i]=i;
  }
  for(int i=0;i<Edge.n;i++){
      int u = find(p,Edge.arr[i].u);
      int v = find(p,Edge.arr[i].v);
      
      if(u!=v){
          mst.arr[mst.n++] = Edge.arr[i];
          union1(p,u,v);
      }
      
  }
  printf("\nThe minimum spaning tree :-");
  display(mst);
  return 0;
}
