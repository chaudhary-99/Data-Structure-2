#include<stdio.h>
int main() {
    int m,n,p,q;
      printf("ENTER THE VALUES OF NUMBER OF ROWS AND COLUMNS of TWO MATRIX");
    scanf("%d %d %d %d",&m,&n,&p,&q);
    int a[m][n];
    int b[p][q];
    int c[10][10];


    if(n==q && m==p){
        
        printf("ENTER THE MATRIX 1\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             scanf("%d",&a[i][j]);
        }
        }

       printf("ENTER THE MATRIX 2\n");
       for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
              scanf("%d",&b[i][j]);
        }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
               c[i][j]=a[i][j]-b[i][j];
            }
        }
     
        printf("PRINTING THE MATRIX\n ");
        for(int j=0;j<m;j++){
            for(int i=0;i<q;i++){
               printf("%d ",c[j][i]);
            
            }
            printf("\n");
        
        }
    }
    else{

        printf("MULTIPLICATION IS NOT POSSIBLE");
    }
    return 0;
}