/* File Input:-
7
0 1 1 0 1 0 0
1 0 0 1 0 1 0
1 0 0 1 0 0 1 
0 1 1 0 1 0 0 
1 0 0 1 0 0 0 
0 1 0 0 0 0 0
0 0 1 0 0 0 0 */

#include <stdio.h>
#include<stdlib.h>
#define n 7
    int visited[7] = {0,0,0,0,0,0,0};
    int A [7][7] ;

    
    struct stack{
        int top;
        int *arr;
        int size;
    };
    
    int isEmpty(struct stack *s){
        if(s->top == -1)
         return 1;
        else
         return 0;
    }
    int isFull(struct stack *s){
        if(s->top == s->size-1)
         return 1;
        else
         return 0;
    }
    
    void push(struct stack *s,int d){
        if(isFull(s))
        return;
        s->top++;
        s->arr[s->top] = d;
    }
    
    int  pop(struct stack *s){
        if(isEmpty(s))
         return -1;
        int d = s->arr[s->top];
        s->top--;
        return d;
    }
    
    void DFS_ITR(int p){
       struct stack s;
        s.top=-1;
        s.size = 100;
        s.arr = (int*)malloc(s.size*sizeof(int));
         push(&s,p);
        visited[p] = 1;
         while(isEmpty(&s)==0){
            
            int d = pop(&s);
            printf(" %d ",d+1);
            for(int i=0;i<7;i++){
                if(A[d][i]==1 && visited[i] ==0)
                 {
                     visited[i] = 1;
                     push(&s,i);
                 }
            }
         }
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
            fscanf(fp,"%d",&A[i][j]);
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Required DFS Traversal is :-");
    DFS_ITR(0);
    

    return 0;
}