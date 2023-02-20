#include <iostream>
#include <vector>
using namespace std;
int InDegree[v]={0};
int OutDegree[v]={0};
void DegreeOfGraph(int v,vector<int>Adjalist[]){
    for(int i=0;i<v;i++){
        OutDegree[i]=Adjalist[i].size();
        printf("OutDegree of %d Vertex :- %d\n",i,Adjalist[i].size());
    }
    
    for(int i=0;i<v;i++){
        for(int j=0;j<Adjalist[i].size();j++){
            Indegree[Adjalist[i][j]]++;
        }
    }
    for(int i=0;i<v;i++){
        printf("InDegree of %d Vertex :- %d\n",i,InDegree[i]);
    }

}       
int main()
{
    int v, e;
    cout << "No. of vetices ";
    cin >> v;
    cout << "No. of edges ";
    cin >> e;
    vector<int> Adjalist[v];
    int Adjacency_Matrix[v][v]={0};
    int Incidency_Matrix[e][v]={0};

    for (int i = 0; i < e; i++)
    {
        cout<<"Edge "<<i+1<<":- ";
        int a,b;
        cin >> a >> b;
        Adjalist[a].push_back(b);
        Adjacency_Matrix[a][b]=1;
        Incidency_Matrix[a][i]=1;
    }
    cout<<"ADJACENCY LINKED LIST\n";
    for (int i = 0; i <v; i++)
    {   
        cout << i << ": ";
        for (int j = 0; j < Adjalist[i].size(); j++)
        {
            cout<< Adjalist[i][j]<<" ";
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
    DegreeOfGraph(v,Adjalist);
    
    return 0;
}