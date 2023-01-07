#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    printf("Enter the Array\n");
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    printf("Printing the Array\n");
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}