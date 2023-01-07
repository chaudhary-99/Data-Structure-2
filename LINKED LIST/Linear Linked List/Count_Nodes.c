#include "LinkedList.h"
#include<stdlib.h>
int count_node(struct node** start){
    int count=0;
    struct node* p=(*start);
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
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
    Traverse(&start);
    printf("\n");
    int c=count_node(&start);
    printf("Total Number of Nodes are %d",c);
    return 0;
}