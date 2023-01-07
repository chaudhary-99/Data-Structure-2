
#include<stdio.h>

int a[3][3];
int b[3][3];

int matrix_addition(int a[3][3],int b[3][3]){
       int c[10][10];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
               c[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("PRINTING THE MATRIX\n ");
        for(int j=0;j<3;j++){
            for(int i=0;i<3;i++){
               printf("%d ",c[j][i]);
            
            }
            printf("\n");
        
        }
}
/*##############################*/
int matrix_determinant(int a[3][3],int b[3][3]){
    int sum1,sum2;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              sum1=sum1+a[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              sum2=sum2+b[i][j];
        }
    }
    return sum1,sum2;

}
int main() {
        printf("ENTER THE MATRIX 1\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
               scanf("%d",&a[i][j]);
            }
        }
        printf("ENTER THE MATRIX 2\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              scanf("%d",&b[i][j]);
        }
        }
        matrix_addition(a,b);
        printf("Determinant of a %d and b %d",matrix_determinant(a,b));
    return 0;
}