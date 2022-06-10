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
    

    void DFS_Itr(int i){
        struct stack s;
        s.top=0;
        s.size = 100;
        s.arr = (int*)malloc(s.size*sizeof(int));
         push(&s,i);
        visited[i] =1;
         printf("\n%d ",i);
         while(isEmpty(&s)==0){
            
            int d = pop(&s);
            for(int i=0;i<7;i++){
                if(A[d][i]==1 && !visited[i])
                 {
                     printf("%d ",i);
                     visited[i] = 1;
                     push(&s,i);
                 }
            }
         }
    }

int main()
{
    DFS_Itr(0);

    return 0;
}
