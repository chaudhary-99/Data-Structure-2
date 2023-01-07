#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
void DFS_visit(int i, vector<int>Adjalist[])
{
    cout<<i<<" ";
    visited[i] = 1;
    for (int j = 0; j < Adjalist[i].size(); j++)
    {
        if (visited[j] == 0)
        {
            DFS_visit(j,Adjalist);
        }
    }
}

void DFS(int v,vector<int>Adjalist[]){
    for (int i = 0; i < v; i++){
        if (visited[i] == 0)
        {
            DFS_visit(i,Adjalist);
        }
    }
}
int main()
{
    // vector<int>precedessor(v,-1);
    int v, e;
    cout << "No. of vetices" << endl;
    cin >> v;
    cout << "No. of edges" << endl;
    cin >> e;
    vector<int> Adjalist[v];
    for (int i = 0; i <e; i++)
    {
        cout<<"Edge "<<i+1<<" ";
        int a,b;
        cin >> a >> b;
        Adjalist[a].push_back(b);
        
    }
    for (int i = 0; i <v; i++)
    {   
        cout << i << ": ";
        for (int j = 0; j <Adjalist[i].size(); j++)
        {
            cout<< Adjalist[i][j]<<" ";
        }
        cout << endl;
    }
   
    DFS(v,Adjalist);
    return 0;
}
