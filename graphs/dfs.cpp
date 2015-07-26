#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#include "../utils/cpputils.h"

/* Directed graph */
class Graph {
    public:
    int nodes;
    vector<vector<int> > g;

    Graph(int nodes) {
        this->nodes = nodes;
        g = vector< vector<int> >(nodes, vector<int>(nodes, 0));
    }

    void addEdge(int from, int to) {
        g[from][to] = 1;
    }

    vector<int> get_children(int node) {
        vector<int> children;
        for(int i=0; i<nodes; i++) {
            if(g[node][i] == 1)
                children.push_back(i);
        }
    //cout<<"children of "<<node<<"are ";
    //print_vi(children);
        return children;
    }
};

void DFS(Graph g, int node, int *visited) {
    cout<<node<<'\n';
    visited[node]=1;
    vector<int> children = g.get_children(node);
    int len = children.size();

    for (int i=0; i<len; i++){
        if (visited[children[i]] == 0) {
            DFS(g, children[i], visited);
        }
    }
}

int main() {
    Graph g = Graph(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int *visited = (int *)malloc(4 * sizeof(int));
    //int visited[4] = {0,0,0,0};
    DFS(g, 0, visited);

    return 0;
}
