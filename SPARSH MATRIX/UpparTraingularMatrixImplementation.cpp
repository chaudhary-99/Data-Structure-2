#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int upparMatrix[n][n];
    vector<int>Array[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                printf("enter value of index (%d ,%d) :",i,j);
                scanf("%d",&upparMatrix[i][j]);
                //Array[n-i+j-1]=upparMatrix[i][j];
            }
            else{
                upparMatrix[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                Array[n-i+j-1]=upparMatrix[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    return 0;

}