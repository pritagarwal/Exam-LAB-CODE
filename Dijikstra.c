/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define INF 9999
	int g[6][6] = { {0, 1, 4, 0, 0, 0},
		        {1, 0, 4, 2, 7, 0},
			{4, 4, 0, 3, 5, 0},
			{0, 2, 3, 0, 4, 6},
			{0, 7, 5, 4, 0, 7},
			{0, 0, 0, 6, 7, 0} };

    int w[6];
    int p[6];
    int mst[6];   
    
void init(int arr[],int v){
    for(int i=0;i<6;i++){
        arr[i] = v;
    }
}

int findMinWeight(){
    
    int min = INF;
    int index;
    for(int i=0;i<6;i++){
        if(mst[i] == -1 && min>w[i]){
            min = w[i];
            index = i;
        }
    }
    
    return index;
}


void dijiksta(){
     
    init(w,INF);
    init(mst,-1);
    
    w[0] = 0;
    p[0] = -1;
    
    for(int j=0;j<6-1;j++){
        int u = findMinWeight();
        mst[u] = 1;
        
        for(int i=0;i<6;i++){
            if(g[u][i]!=0 && mst[i] ==-1 && w[u]!= INF && w[i]>(w[u]+g[u][i]))
            {
                p[i] = u;
                w[i] = w[u]+g[u][i];
            }
        }
    }
    
    int total =0;
    for (int i=0;i<6;i++){
        total+=w[i];
    }
    
    printf("\n The Shortest tree traversal is: -");
    printf("\n\tU\tV\tW");
    for(int i=1;i<6;i++){
        printf("\n\t%d\t%d\t%d",p[i],i,g[p[i]][i]);
    }
}


int main()
{
    dijiksta();

    return 0;
}

