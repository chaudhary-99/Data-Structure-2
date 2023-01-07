#include<iostream>
using namespace std;
int arr[5]={1,2,3,4,5};
void Printing_Array_after_inserting_given_element(int c){
    int y=5;
    arr[y]=c;
    y=y+1;
    for(int i=0;i<y;i++){
        cout<<arr[i];
    }

}
int main(){
    int n;
    cin>>n;
    Printing_Array_after_inserting_given_element(n);
    return 0;
}