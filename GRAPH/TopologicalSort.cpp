#include <iostream>
#include <vector>
#include<queue>
using namespace std;

void DegreeOfGraph(int v,vector<int>Adjalist[]){
    int InDegree[v]={0};
    for(int i=0;i<v;i++){
        printf("OutDegree of %d Vertex :- %d\n",i,Adjalist[i].size());
    }
    
    for(int i=0;i<v;i++){
        for(int j=0;j<Adjalist[i].size();j++){
            InDegree[Adjalist[i][j]]++;
        }
    }
    for(int i=0;i<v;i++){
        printf("InDegree of %d Vertex :- %d\n",i,InDegree[i]);
    }
    printf("TOPOLOGICAL SORT\n");
    queue<int>q;
    for(int i=0;i<v;i++){
        if(InDegree[i]==0){
            q.push(i);
            InDegree[i]=-1;
        }
    }
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<Adjalist[x].size();i++){
            InDegree[Adjalist[x][i]]--;
        }
        for(int i=0;i<v;i++){
        if(InDegree[i]==0){
            q.push(i);
            InDegree[i]=-1;
        }
    }
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
    int Adjacency_Matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            Adjacency_Matrix[i][j]=0;
        }
    }
    int Incidency_Matrix[e][v]={0};
     for(int i=0;i<e;i++){
        for(int j=0;j<v;j++){
            Incidency_Matrix[i][j]=0;
        }
    }

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