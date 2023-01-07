#include<iostream>
int a[8]={3,5,0,6,7,1,4,2};
void Finding_given_element_in_array(int c){
	for(int i=0;i<7;i++){
		if(a[i]==c){
		    printf("%d",i);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	Finding_given_element_in_array(n);
	return 0;
}