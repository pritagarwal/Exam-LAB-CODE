/*5
0 7 0 2 0
0 0 1 2 0 
0 0 0 0 4
0 3 8 0 5
0 0 5 0 0*/


#include <stdio.h>
#define INF 9999
#define n 5
	int g[n][n] ;

    int w[n];
    int p[n];
    int mst[n];   
    
void init(int arr[],int v){
    for(int i=0;i<n;i++){
        arr[i] = v;
    }
}

int findMinWeight(){
    
    int min = INF;
    int index;
    for(int i=0;i<n;i++){
        if(mst[i] == -1 && min>w[i]){
            min = w[i];
            index = i;
        }
    }
    
    return index;
}



void path(int dest)
{
    if(p[dest]==-1)
    {
        printf(" S ");
        return;
    }
    else
    {
        path(p[dest]);
        printf(" -> %c ",dest+65);
    }
}


void dijiksta(){
     
    init(w,INF);
    init(mst,-1);
    
    w[0] = 0;
    p[0] = -1;
    
    for(int j=0;j<n-1;j++){
        int u = findMinWeight();
        mst[u] = 1;
        
        for(int i=0;i<n;i++){
            if(g[u][i]!=0 && mst[i] ==-1 && w[u]!= INF && w[i]>(w[u]+g[u][i]))
            {
                p[i] = u;
                w[i] = w[u]+g[u][i];
            }
        }
    }
    
    int total =0;
    for (int i=0;i<n;i++){
        total+=w[i];
    }
    
    printf("\n The Shortest tree traversal is: -");
    printf("\n\tU\tV\tW");
    for(int i=1;i<n;i++){
        if(p[i] == 0)
        printf("\n\t%c\t%c\t%d",83,i+65,g[p[i]][i]);
        else 
        printf("\n\t%c\t%c\t%d",p[i]+65,i+65,g[p[i]][i]);
    }
    
    printf("\nEnter the Destination vertex :-");
    char ch;
    scanf(" %c",&ch);
    path((int)ch - 65);
}


int main()
{
    FILE *fp;
    fp = fopen("Ex.txt","r");
    if(fp ==NULL)
     printf("NULL");
     
    int n1;
    fscanf(fp,"%d",&n1);

    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++){
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    
    fclose(fp);
    
    dijiksta();

    return 0;
}