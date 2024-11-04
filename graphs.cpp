#include<iostream>
using namespace std;
#include<list>
#include<queue>
#include<stack>
#include<vector>

class graph
{
private:
    int vertices;
    vector<list<int>> adjlist;
public:
    graph(int vertice);
    void addedges(int u,int v);
    void BFS(int start);
    void DFS(int start);
};

graph::graph(int v)
{
    vertices=v;
    adjlist.resize(v);
}

void graph::addedges(int u, int v)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}

void graph::BFS(int start)
{
    vector<bool> visited(vertices,false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        for(int neighbour:adjlist[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;
}

void graph::DFS(int start)
{
    vector<bool> visited(vertices, false);
    stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
            {
                visited[node] = true;
                cout << node << " ";
                for (auto it = adjlist[node].rbegin(); it != adjlist[node].rend(); ++it)
                {
                    if (!visited[*it])
                    {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
}

int main()
{
    graph g(7);
    g.addedges(0, 1);
    g.addedges(0, 2);
    g.addedges(1, 3);
    g.addedges(1, 4);
    g.addedges(2, 5);
    g.addedges(2,6);

    cout<<"BFS TRAVERSAL: "<<endl;
    g.BFS(0);

    cout<<"DFS TRAVERSAL: "<<endl;
    g.DFS(0);

    return 0;
}
