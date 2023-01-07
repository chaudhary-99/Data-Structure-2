#include<stdio.h>
int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int b[4][4];
int c[4][4];
void Matrix_transpose_for_90(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            b[i][j]=a[j][i];
        }
    }
}
void Matrix_transpose_for_180(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            c[i][j]=b[j][i];
        }
    }
} 	


void Col_exchange_for_90(){
	for(int d=0;d<4;d++){
        int r=0;
        int j=3;
        while(r<j){
            int t=b[r][d];
            b[r][d]=b[j][d];
            b[j][d]=t;
            j--;
            r++;
        }
    }
}
void Col_exchange_for_180(){
	for(int r=0;r<4;r++){
        int d=0;
        int j=3;
        while(d<j){
            int t=c[d][r];
            c[d][r]=c[j][r];
            c[j][r]=t;
            j--;
            d++;
        }
    }
}


void Matrix_printing(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Making clock 90 rotated matrix\n");
    Matrix_transpose_for_90();
    Col_exchange_for_90();
    printf("Making clock 180 rotated matrix\n");
    Matrix_transpose_for_180();
    Col_exchange_for_180();
    
    Matrix_printing();
    return 0;
}