#include "LinkedList.h"

int main(){
    struct node* start;
    start=NULL;
    InsBeg(&start,10);
    OrderedIns(&start,30);
    OrderedIns(&start,99);
    OrderedIns(&start,20);
    OrderedIns(&start,9);
    OrderedIns(&start,13);
    OrderedIns(&start,19);
    Traverse(&start);
    return 0;
}