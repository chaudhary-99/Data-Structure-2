#include "LinkedList.h"
int count_Even_node(struct node** start){
    int countEven=0;
   
    struct node* p=(*start);
    while(p!=NULL){
        if((p->info)%2==0){
            countEven++;
        }
        p=p->next;
    }
    return countEven;
}

int count_Odd_node(struct node** start){
    int countOdd=0;
    struct node* p=(*start);
    while(p!=NULL){
        if((p->info)%2!=0){
            countOdd++;
        }
        p=p->next;
    }
    return countOdd;
}

int main(){
    struct node* start;
    start=NULL;
    struct node* p;
    InsBeg(&start,100);
    InsBeg(&start,200);
    InsBeg(&start,300);
    InsBeg(&start,400);
    InsEnd(&start,500);
    InsBeg(&start,900);
    InsBeg(&start,901);
    InsBeg(&start,750);
    printf("Total Number of Even Node %d\n",count_Even_node(&start));
    printf("Total Number of Odd Node %d\n",count_Odd_node(&start));
    return 0;
}