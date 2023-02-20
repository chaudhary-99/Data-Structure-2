#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int TriDiagonalMatrix[n][n];
    int Array[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i||j==i-1||i==j-1){
                printf("enter value of index (%d ,%d) :",i,j);
                scanf("%d",&TriDiagonalMatrix[i][j]);
                Array[2*i+j-2]=TriDiagonalMatrix[i][j];
            }
            else{
                TriDiagonalMatrix[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        
            printf("%d ",Array[i]);
        
        
    }
    return 0;

}