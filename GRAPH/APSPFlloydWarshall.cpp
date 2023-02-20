#include <iostream>
#include <vector>
using namespace std;              
int main()
{
    int v, e;
    cout << "No. of vetices ";
    cin >> v;
    cout << "No. of edges ";
    cin >> e;
    vector<pair<int,int>> Adjalist[v];
    int Adjacency_Matrix[v][v];
    int Incidency_Matrix[e][v];
    int Weight_Matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            Adjacency_Matrix[i][j]=0;
            Weight_Matrix[v][v]=0;
        }
    }
    for(int i=0;i<e;i++){
        for(int j=0;j<v;j++){
            Incidency_Matrix[i][j]=0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        cout<<"Edge and weight "<<i+1<<":- ";
        int a,b,w;
        cin >> a >> b>>w;
        Adjalist[a].push_back(make_pair(b,w));
        Weight_Matrix[a][b]=w;
        Adjacency_Matrix[a][b]=1;
        Incidency_Matrix[a][i]=1;
    }
    cout<<"ADJACENCY LINKED LIST\n";
    for (int i = 0; i <v; i++)
    {   
        cout << i << ": ";
        for (int j = 0; j < Adjalist[i].size(); j++)
        {
            cout<< Adjalist[i][j].first<<" "<<Adjalist[i][j].second;
        }
        cout << endl;
    }
    cout<<"ADJACENCY MATRIX\n";
    for (int i = 0; i <v; i++)
    {   
        cout << i << ": ";
        for (int j = 0; j < v; j++)
        {
            cout<< Adjacency_Matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"INCIDENCE MATRIX\n";
    for (int i = 0; i <v; i++)
    {   
        cout << i << ": ";
        for (int j = 0; j < e; j++)
        {
            cout<< Incidency_Matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"WEIGHT MATRIX\n";
    for (int i = 0; i <v; i++)
    {   
        cout << i<<"-"<<j << ": ";
        for (int j = 0; j < v; j++)
        {
            cout<<Weight_Matrix[i][j]<<" ";
        }
        cout << endl;
    }

    

    return 0;
}