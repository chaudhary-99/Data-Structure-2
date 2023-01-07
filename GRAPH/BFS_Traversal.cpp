#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS_Traversal(int v, vector<int> Adjalist[])
{
    int visited[v] = {0};
    queue<int> Q;
    Q.push(0);
    visited[0] = 1;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < Adjalist[x].size(); i++)
        {
            if (visited[Adjalist[x][i]] == 0)
            {
                Q.push(Adjalist[x][i]);
                visited[Adjalist[x][i]] = 1;
            }
        }
        cout << x << " ";
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

    for (int i = 0; i < e; i++)
    {
        cout << "Edge " << i + 1 << ":- ";
        int a, b;
        cin >> a >> b;
        Adjalist[a].push_back(b);
        Adjalist[b].push_back(a);
    }
    cout << "ADJACENCY LINKED LIST\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < Adjalist[i].size(); j++)
        {
            cout << Adjalist[i][j] << " ";
        }
        cout << endl;
    }
    BFS_Traversal(v, Adjalist);
    return 0;
}