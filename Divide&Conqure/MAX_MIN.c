/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <limits.h>
#include <stdio.h>
typedef struct pair{
    int max;
    int min;
}pair;

void max_min(int arr[],int i,int j,pair *p){
    if(i == j){
        if(p->max<arr[i])
        p->max =arr[i];
        if(p->min>arr[i])
        p->min = arr[i];
        
    }
    else if(j == i+1){
        if(arr[i]>arr[j]){
            if(p->max<arr[i])
             p->max = arr[i];
             if(p->min>arr[j])
              p->min = arr[j];
             
              
        }
    
        else{
         
            if(p->max<arr[j])
             p->max = arr[j];
             
             if(p->min>arr[i])
              p->min = arr[i];
        
          
        }
        
        
    }
    else{
        
        
        int mid = i+(j-i)/2;
        
        max_min(arr,i,mid,p);

        max_min(arr,mid+1,j,p);
       
    }
    
}


int main()
{
    int arr[] = {1,2,5,0,9};
    pair p;
    p.max =INT_MIN;
    p.min =INT_MAX;
    max_min(arr,0,4,&p);
    printf("\nMax = %d ,Min = %d",p.max,p.min);
   

    return 0;
}
