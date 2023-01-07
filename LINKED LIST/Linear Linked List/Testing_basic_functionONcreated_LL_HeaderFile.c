#include "LinkedList.h"
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

    int c;
    scanf("%d",&c);
    struct node* n;
    n=start;
    while(c>0){
        n=n->next;
        c--;
    }
    InsAft(&n,350);
    
    Traverse(&start);
    return 0;
}