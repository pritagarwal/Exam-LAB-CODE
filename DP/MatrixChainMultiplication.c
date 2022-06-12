/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define INF 9999999
char name ='A';

void print(int i, int j, int n, int b[5][5])
				
{
   
	if (i == j) {
	    printf("%c",name++);
		return;
	}
	printf("(");


	print(i,b[i][j], n,b);

	print(b[i][j]+ 1, j, n,	b);
				
	printf(")");
}

void matrixchain(int p[],int n){
    int m[n][n];
    int b[5][5];
    for(int i=1;i<n;i++){
        m[i][i] = 0;
    }
    
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
             int j = i+l-1;
            m[i][j] = INF;
            for(int k=i;k<=j-1;k++){
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    
                    m[i][j] = q;
                    b[i][j] = k;
                }
            }
        }
    }
   
    printf("\nThe subExpression :-");
    print(1,n-1,n,b);
    printf("\nOptimal solution :- %d\n",m[1][n-1]);
    
}

int main()
{
    int arr[]={40,20,30,10,30};
    matrixchain(arr,5);

    return 0;
}
