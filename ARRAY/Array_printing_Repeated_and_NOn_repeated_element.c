#include<stdio.h>
int arr[8]={3,4,7,4,7,1,4,2};
void Printing_Non_Repeated_element_of_array(){
	for(int i=0;i<8;i++){
		int flag=0;
		for(int j=i+1;j<8;j++){
			if(arr[i]==arr[j]){
				arr[j]=0;
				flag=1;
			}	
		}
		if(flag==1){
			arr[i]=0;
		}
	}
	for(int i=0;i<8;i++){
		if(arr[i]!=0)
		   printf("%d\n",arr[i]);
	}
}
void Printing_Repeated_element_of_array(){
	
}
int main(){
	Printing_Repeated_element_of_array();
	Printing_Non_Repeated_element_of_array();
	return 0;
}