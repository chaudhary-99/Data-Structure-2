#include<stdio.h>
#include<math.h>
int no_of_digits(int num){
	int c=0;
	while(num>0){
		int t=num%10;
		c++;
		num=num/10;
	}
	return c;
}
int powh(int n,int a)
{
	int t=1;
	while(a!=0){
	    t=t*n;
	    a--;
	}
	return t;
}
int midsquare(int key,int ts){
	int a=no_of_digits(ts-1);
	int b=no_of_digits(key);
	int c=(2*b-a)/2;
	int x=(key*key)/powh(10,c);
	int l=x%powh(10,a);
	l=l%ts;
	return l;
}
int main(){
	int key=48779259;
	int ts=8;
	printf("%d",midsquare(key,ts));
	return 0;
}