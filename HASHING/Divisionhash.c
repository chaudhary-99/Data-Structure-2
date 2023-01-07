#include<stdio.h>
#include<math.h>
int prime(int num){
    int x=sqrt(num);
    int flag=1;
    for(int i=2;i<=x;i++){
    	if(num%i==0){
    		flag=0;
    		break;
		}
	}
	
	if(flag==0){
		return 0;
	}
	else{
		return 1;
	}
}
int division_hash(long long key,int ts){
    int a=0;
	while(a!=1){
		a=prime(ts);
		if(a==1){
			break;
		}
		ts--;
	}
	int l=key%ts;
	return l;
}
int main(){
	long long key=48779259;
	int ts=100;
	printf("ff");
	printf("\n%d",division_hash(key,ts));
	return 0;
}