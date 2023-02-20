#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int lowerMatrix[n][n];
    vector<int>Array(n*n);
    int t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i){
                int t=i*(i-1);
                t=t/2;
                printf("enter value of index (%d ,%d) :",i,j);
                scanf("%d",&lowerMatrix[i][j]);
                Array[t+j]=lowerMatrix[i][j];
            }
            else{
                lowerMatrix[i][j]=0;
            }
        }
    }
    for(int i=1;i<Array.size();i++){
        printf("%d ",Array[i]);
    }
    return 0;

}