
//Text file for graph input
/*6
0 1 0 0 0 0 
0 0 1 0 0 5 
0 0 0 4 1 0 
0 0 0 0 0 0 
0 0 0 2 0 0 
1 0 0 0 2 0 */



#include<stdlib.h>
#include <stdio.h>
#define INF 9999
	int g[6][6];
		       
    int w[6];
    int p[6];
     
    
void init(int arr[],int v){
    for(int i=0;i<6;i++){
        arr[i] = v;
    }
}

void bell(){
     
    init(w,INF);
    w[0] = 0;
    p[0] = -1;
    
      for(int j=0;j<6-1;j++){
        for(int i=0;i<6;i++){
           
            if(g[j][i]!=0 && w[j]!= INF && w[i]>(w[j]+g[j][i]))
            {
                p[i] = j;
                w[i] = w[j]+g[j][i];
            }
        }
    }
    
    for(int j=0;j<6;j++){
        for(int i=0;i<6;i++){
           
            if(g[j][i]!=0 && w[j]!= INF && w[i]>(w[j]+g[j][i]))
            {
              printf("Negative Edge weight Cycle");
              return;
            }
        }
    }
    printf("\n The Single Source Shortest path  is: -");
    printf("\n\tU\tV\tCost From Source\n");
    for(int i=1;i<6;i++){
         if(p[i]==0)
          printf("\t%c\t%c\t   %d",'S',i+64,w[i]);
         else 
        printf("\n\t%c\t%c\t   %d",p[i]+64,i+64,w[i]);
    }
}

int main()
{
    FILE *fp;
    fp = fopen("Ex.txt","r");
    if(fp ==NULL)
     printf("NULL");
     
    int n;
    fscanf(fp,"%d",&n);
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    } 
    bell();
    fclose(fp);
    return 0;
}

