#include<iostream>
int main(){
	int a[8]={3,5,0,6,7,1,4,2};
    for(int i=0;i<8/2;i++){
       int temp=a[i];
       a[i]=a[7-i];
       a[7-i]=temp;
    }
    for(int i=0;i<8;i++){
          printf("%d ",a[i]);
    }
	return 0;
}