#include<stdio.h>
int m=6,n=5;
int a1[6]={2,3,4,5,9,10};
int a2[5]={3,5,6,7,8};
int c[10];
int d[10];
int e[10];
int l1;
int l2;
int Set_difference_of_setA_to_SetB(){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a1[i]<a2[j]){
            c[k]=a1[i];
            i++;
            k++;    
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else{
            j++;
            i++;
        }
    }
    while(i<m){
        c[k]=a1[i];
        k++;
        i++;
    }
    l1=k;
    printf("Set_difference_of_setA_to_SetB ");
    for(int y=0;y<k;y++){
        printf("%d ",c[y]);
    }
    printf("\n");
}
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
int Set_difference_of_setB_to_SetA(){
    int i=0,j=0,k=0;
    
    while(i<m && j<n){
        if(a1[i]<a2[j]){
           
            i++;
                
        }
        else if(a1[i]>a2[j]){
            d[k]=a2[j];
            j++;
            k++;
        }
        else{
            j++;
            i++;
        }
    }
    while(j<n){
        d[k]=a2[j];
        k++;
        j++;
    }
    l2=k;
     printf("Set_difference_of_setB_to_SetA ");
    for(int y=0;y<k;y++){
        printf("%d ",d[y]);
    }
    printf("\n");
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
int Set_Union_of_setA_and_SetB(){
     int i=0,j=0,k=0;
    
    while(i<l1 && j<l1){
        if(c[i]<d[j]){
            e[k]=c[i];
            i++;
            k++;
        }
        else if(c[i]>d[j]){
            e[k]=d[j];
            k++;
            j++;
        }
        else{
            e[k]=c[i];
            k++;
            i++;
            j++;
        }
    }
    while(i<l1){
        e[k]=c[i];
        k++;
        i++;
    }
    while(j<l2){
        e[k]=d[j];
        k++;
        j++;
    }
    printf("Symmetric_Difference_of_setA_and_SetBS_ ");
    for(int y=0;y<k;y++){
        printf("%d ",e[y]);
    }
    printf("\n");
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%*/
int main(){
    Set_difference_of_setA_to_SetB();
    Set_difference_of_setB_to_SetA();
    Set_Union_of_setA_and_SetB();
    return 0;
}