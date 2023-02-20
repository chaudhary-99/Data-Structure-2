#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int DiagonalMatrix[n][n];
    vector<int>Array(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i){
                printf("enter value of index (%d ,%d) :",i,j);
                scanf("%d",&DiagonalMatrix[i][j]);
                Array[i]=DiagonalMatrix[i][j];
                
            }
            else{
                DiagonalMatrix[i][j]=0;
            }
        }
    }
    for(int i=0;i<Array.size();i++){
        printf("%d ",Array[i]);
    }
    return 0;

}