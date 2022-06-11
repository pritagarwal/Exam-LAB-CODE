/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define INF 999
#include<stdlib.h>
int g[4][4];
int n;

void floyd(){  
    
    int d[n][n];
  
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
             d[i][j] = g[i][j];
        }
    }
   
    
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k] == INF || d[k][j] == INF){
                    continue;
                }
                else{
                    if(d[i][k]+d[k][j]<d[i][j])
                     d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(d[i][i] <0){
            printf("Negative edge weight present");
            return;
        }
    }
    printf("All shortest path:-\n");
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(d[i][j] == 0||d[i][j] == INF)
           continue;
           printf("%c  %c %d\n",i+65,j+65,d[i][j]);
       }
       printf("\n---------------\n");
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
