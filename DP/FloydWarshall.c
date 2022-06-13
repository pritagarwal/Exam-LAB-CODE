
/*4
0 10 5 3 
1 0 999 999 
999 2 0 999 
999 999 2 0 */

#include <stdio.h>
#define INF 999
#include<stdlib.h>
int g[4][4];
int n;

void print(int arr[4][4],int p[4][4]){
    printf("\n");
    for(int i=0 ;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j] == INF)
            printf("I ");
            else
            printf("%d ",arr[i][j]);
        }
        printf("\t");
         for(int j=0;j<4;j++){
             if(p[i][j] == -1)
              printf("N ");
              else
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}


void sortPath(int u,int v,int p[4][4]){
    
    if(u == v){
        printf(" %d ",u+1);
    }
    else if(p[u][v] == -1){
        printf("NO path exist");
    }
    else{
        sortPath(u,p[u][v],p);
        printf(" %d ",v+1);
    }
    
    
    
}

void floyd(){  
    
    int d[n][n];
    int p[n][n];
  
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
             d[i][j] = g[i][j];
             if(g[i][j] == 0 || g[i][j] == INF)
              p[i][j] = -1;
             else
              p[i][j] = i;
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k] == INF || d[k][j] == INF){
                    continue;
                }
                else{
                    if(d[i][k]+d[k][j]<d[i][j]){
                        d[i][j] = d[i][k]+d[k][j];
                        p[i][j] = p[k][j];
                    }
                     
                     
                }
            }
        }
        
         print(d,p);
    }
       
        printf("Enter the u v :- ");
        int u, v;
        scanf("%d %d",&u,&v);
        sortPath(u-1,v-1,p);
       
    for(int i=0;i<n;i++){
        if(d[i][i] <0){
            printf("Negative edge weight present");
            return;
        }
    }
}

int main()
{
    FILE *fp;
    fp = fopen("Ex.txt","r");
    fscanf(fp,"%d",&n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    floyd();
    fclose(fp);
  return 0;
}