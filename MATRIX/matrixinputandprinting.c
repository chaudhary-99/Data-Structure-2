#include<stdio.h>
int main() {
    int m,n;
    printf("ENTER THE VALUES OF NUMBER OF ROWS AND COLUMNS");
    scanf("%d %d",&m,&n);
    int a[m][n];

    printf("ENTER THE ARRAY");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          scanf("%d ",&a[i][j]);
        }
    }


    printf("PRINTING THE ARRAY\n");
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
               printf("%d ",a[j][i]);
            
        }
        printf("\n");
        
    }
    return 0;
}
