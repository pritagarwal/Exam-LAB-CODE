/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
    int visited[7] = {0,0,0,0,0,0,0};
    int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    
    
    void DFS(int i){
        
        printf("%d ",i);
        visited[i] = 1;
        for(int j=0;j<7;j++){
            if(A[i][j]==1 && !visited[j]){
                DFS(j);
            }
        }
        
        
    }

int main()
{
    DFS(0);

    return 0;
}
