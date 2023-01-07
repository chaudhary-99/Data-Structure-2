#include<iostream>
using namespace std;
int arr[5]={1,2,3,5,6};
void Printing_after_inserting_given_element_in_sorted_array(int c){

    int y=5;
    y=y+1;
    while(y--){
        
        if(arr[y-1]>c){
           arr[y]=arr[y-1];
        }
        else{
            arr[y]=c;
            break;
        }
    }
   
    for(int i=0;i<6;i++){
        cout<<arr[i];
    }

}
int main(){
    int n;
    cin>>n;
    Printing_after_inserting_given_element_in_sorted_array(n);
    return 0;
}