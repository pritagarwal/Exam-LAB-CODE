/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
typedef struct Job{
    char id[5];
    int d;
    int p;
} Job;


void print(Job j[],int n){
    
    printf("%10s %10s %10s","JOB","DEADLINE","PROFIT\n");
    for(int i=0;i<n;i++){
        printf("%10s %10d %10d\n",j[i].id,j[i].d,j[i].p);
    }
    
}
int min(int x,int y){
    if(x<y)
     return  x;
    return y; 
}


void jobSequenc(Job j[],int n){
    
    int profit=0;
    int dmax=0;
    for(int i=0;i<n;i++){
        if(j[i].d>dmax){
            dmax= j[i].d;
        }
    }
    
    int slot = min(dmax,n);
    int t[slot+1];
    for(int i=1;i<=slot;i++){
        t[i] = -1;
    }
    
    int k=0;
    int f=0;
    
    for(int i=1;i<=n;i++){
        k = min(n,j[i-1].d);
        while(k>=1){
            if(t[k] == -1){
                t[k] = i-1;
                f++;
                break;
            }
            else
             k--;
        }
        if(f == slot){
            break;
        }
        
    }
    printf("\nRequired Jobs:-");
    for(int i=1;i<=slot;i++){
        printf("%s  ",j[t[i]].id);
    }
    for(int i=1;i<=slot;i++){
        profit = profit+j[t[i]].p;
    }
    printf("\nMAX PROFIT :- %d",profit);
}


int main()
{
    
    Job job[] = {{"j1",1,3},{"j2",3,5},{"j3",4,20},{"j4",3,18},{"j5",2,1},{"j6",1,6},{"j7",2,30}};
    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-1-i;j++){
            
            if(job[j].p<job[j+1].p){
                Job t = job[j];
                job[j]= job[j+1];
                job[j+1] = t;
            }
            
        }
    }
    
    printf("\n");
    print(job,5);
    
    jobSequenc(job,5);
    
    
    return 0;
}
