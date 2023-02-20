#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>Ht[15];
    int n,x,r;
    cout<<"How many data element are to be stored\n";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        r=x%10;
        Ht[r].push_back(x);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<Ht[i].size();j++){
            cout<<Ht[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}