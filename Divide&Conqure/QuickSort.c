/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void swap(int arr[],int i,int j){
    int t  = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int  partation(int arr[],int s,int e){
    
    int p = s;
    int start = s;
    int end = e;
    while(start<end){
        while(start<=e && arr[p]>=arr[start])
         start++;
        while(end>=s && arr[p]<arr[end]) 
         end--;
         
         if(start<=end){
             swap(arr,start,end);
         }
    }
    
    swap(arr,end,p);
    return end;
}



void quicksort(int arr[],int s,int e){
    if(s<e){
        int p = partation(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,e);
    }
    
}



void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[] = {2,3,1,4,0};
    quicksort(arr,0,4);
    print(arr,5);


    return 0;
}
