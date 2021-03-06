
#include <stdio.h>
float q[7];


void swap(int arr[],int i,int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void print(int id[],int arr[],int p[],float f[],int n){
    printf("SL No.\tWEIGHT\tPROFIT\tTaken\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%.2f\n",id[i],arr[i],p[i],f[i]);
    }
    printf("\n");
}


 float knapsack(int w[],int p[],float c,int i,int n){
    
    float profit = 0.0;
    int k=0;

    while(i<n){
        if(c>=w[i]){
            profit = profit+p[i];
            c = c-w[i];
            q[k++] = 1.0;
        }
        else {
            float a = p[i];
            float b = w[i];
            float d = a/b;
            float f = c;
            q[k++] = c/b;
            profit = profit+(f*d);
            break;
            
        }
        i++;
    }
    return profit;
}




int main()
{
    int id[] ={1,2,3,4,5,6,7};
    int w[] = {2,3,5,7,1,4,1};
    int p[] = {10,5,15,7,6,18,3};
    int c = 15;
    float r[7];
    for(int i=0;i<7;i++){
        r[i] = p[i]/w[i];
    }

    for(int i=0;i<7;i++){
        for(int j=0;j<7-i-1;j++){
            if(r[j]<r[j+1]){
                swap(w,j,j+1);
                swap(p,j,j+1);
                swap(id,j,j+1);
                float t = r[j];
                r[j] = r[j+1];
                r[j+1] = t;
            }
        }
    }
    
    float profit = knapsack(w,p,c,0,7);
    printf("MAX PROFIT :- %f\n",profit);
   
   print(id,w,p,q,7);

    return 0;
}