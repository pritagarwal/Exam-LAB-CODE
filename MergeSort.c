/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


void merge(int arr[],int s,int m,int e){
    
    int ans[e-s+1];
    int i=s;
    int j =m+1;
    int k=0;
    while(i<=m && j<=e){
        if(arr[i]<=arr[j])
         ans[k++] = arr[i++];
         else
         ans[k++] = arr[j++];
         
    }
    
    while(i<=m){
        ans[k++] = arr[i++];
    }
     while(j<=e){
        ans[k++] = arr[j++];
    }
    
    for(int i=0;i<k;i++){
        arr[s+i]= ans[i];
    }
}

void mergesort(int arr[],int s,int e){
    
    if(e-s <1){
        return;
    }
    
    int mid = s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
    
    
    
}


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


int main()
{
    int arr[] = {2,3,1,4,0};
    mergesort(arr,0,4);
    print(arr,5);


    return 0;
}
