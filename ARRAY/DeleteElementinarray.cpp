#include<stdio.h>
int a[8]={3,5,0,6,7,1,4,2};
void Printing_Array_after_deleting_given_element(int c){
	int y=8;
	y=y-1;
	for(int i=0;i<7;i++){
		if(a[i]==c){
			a[i]=a[i+1];
			c=a[i+1];
		}
	}
	for(int j=0;j<7;j++){
		printf("%d",a[j]);
	}
		
}
int main(){
	int n;
	scanf("%d",&n);
	Printing_Array_after_deleting_given_element(n);

	return 0;
}