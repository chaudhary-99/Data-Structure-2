# include<stdio.h>
int main(){
    int n1;
	printf("ENTER SIZE OF SET 1 N1: ");
	scanf("%d",&n1);
	
	
	int n2;
	printf("ENTER SIZE OF SET 2 N2: ");
	scanf("%d",&n2);
	
	
	int a1[n1],a2[n2];
	
	printf("ENTER SETS1 ");
	for(int a=0;a<n1;a++){
        scanf("%d",&a1[a]);
    }
    
    printf("ENTER SETS2 ");
	for(int b=0;b<n2;b++){
        scanf("%d",&a2[b]);
    }
    int c[9];
    int i=0,j=0,k=0;
    
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            c[k]=a1[i];
            i++;
            k++;
        }
        else if(a1[i]>a2[j]){
            c[k]=a2[j];
            k++;
            j++;
        }
        else{
            c[k]=a1[i];
            k++;
            i++;
            j++;
        }
    }
    while(i<n1){
        c[k]=a1[i];
        k++;
        i++;
    
    }
    while(j<n2){
        c[k]=a2[j];
        k++;
        j++;
    }
    printf("PRINTING MERGED ARRAY:");
    for(int y=0;y<k;y++){
        printf(" %d",c[y]);
    }
    return 0;
}