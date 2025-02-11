#include <bits/stdc++.h>
using namespace std;

//DFS(Depth First Search)

struct Edge{
    int src;
    int dest;
};

class Graph{
    public: 
        vector<vector<int>> adjlist;
        Graph(vector<Edge> const&edges,int n)
        {
            adjlist.resize(n);
            for(auto &edge : edges)
            {
                adjlist[edge.src].push_back(edge.dest);
                adjlist[edge.dest].push_back(edge.src);
            }
        }
};

void DFS(Graph const &graph,int v,vector<bool> &discovered)
{
    stack<int> q;
    discovered[v] = true;
    q.push(v);
    while(!q.empty())
    {
        v = q.top();
        q.pop();
        cout << v << " ";
        for(int u:graph.adjlist[v])
        {
            if(!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
	vector<Edge> edge = {{1,2},{1,3},{1,4},{2,5},{1,6},{5,9},{5,10},{4,7},{4,8},{7,11},{7,12}};
	int n = 15;
	Graph graph(edge,n);
	vector<bool> discovered(n,false);
	for(int i=0;i<n;i++)
	{
	    if(discovered[i]==false)
	    {
	        DFS(graph,i,discovered);
	    }
	}
	return 0;
}
