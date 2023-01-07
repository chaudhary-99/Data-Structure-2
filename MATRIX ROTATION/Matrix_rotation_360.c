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

void Matrix_transpose_for_270(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            b[i][j]=c[j][i];
        }
    }
} 	

void Matrix_transpose_for_360(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            c[i][j]=b[j][i];
        }
    }
} 	


void Row_exchange_for_90(){
	for(int r=0;r<4;r++){
        int d=0;
        int j=3;
        while(d<j){
            int t=b[r][d];
            b[r][d]=b[r][j];
            b[r][j]=t;
            j--;
            d++;
        }
    }
}
void Row_exchange_for_180(){
	for(int r=0;r<4;r++){
        int d=0;
        int j=3;
        while(d<j){
            int t=c[r][d];
            c[r][d]=c[r][j];
            c[r][j]=t;
            j--;
            d++;
        }
    }
}

void Matrix_printing(){
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Making clock 90 rotated matrix\n");
    Matrix_transpose_for_90();
    Row_exchange_for_90();
     printf("Making clock 180 rotated matrix\n");
    Matrix_transpose_for_180();
    Row_exchange_for_180();
    printf("Making clock 270 rotated matrix\n");
    Matrix_transpose_for_270();
    Row_exchange_for_90();
    printf("Making clock 360 rotated matrix\n");
    Matrix_transpose_for_360();
    Row_exchange_for_180();
    Matrix_printing();
    return 0;
}