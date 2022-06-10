
#include <stdio.h>

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}



void heapify(int arr[] ,int n,int i){
    int left = i*2+1;
    int right =i*2+2;
    int max = i;
    if(left<n && arr[left]>arr[max])
    max = left;
    if(right<n && arr[right]> arr[max])
    max = right;
    
    if(max!=i){
        int t = arr[i];
        arr[i]= arr[max];
        arr[max] = t;
        heapify(arr,n,max);
    }
}

void heapsort(int arr[],int n){
    
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
      
    }
      
    for(int i=n-1;i>=0;i--){
        
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr,i,0);
    }
    
    
}



int main()
{
    int arr[] = {2,4,1,5,6,3};
    printf("Before heapsort:-");
    print(arr,6);
    heapsort(arr,6);
    printf("After heapsort :-");
    print(arr,6);

    return 0;
}
