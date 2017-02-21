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
        return children;
    }
};

void topo(Graph g, int node, int *visited, vector<int> *stack) {

    /* Print current node */
    //cout<<node<<'\n';
    visited[node]=1;

    /* Find curret node's children, and run DFS on each of them */
    vector<int> children = g.get_children(node);
    int len = children.size();

    for (int i=0; i<len; i++){
        if (visited[children[i]] == 0) {
            topo(g, children[i], visited, stack);
        }
    }

    stack->push_back(node);
}

int main() {
    /* Image of graph at http://imgur.com/ZGfGIO0/ */
    Graph g = Graph(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 6);
    g.addEdge(1, 7);
    g.addEdge(5, 3);
    g.addEdge(4, 5);
    g.addEdge(6, 5);
    g.addEdge(7, 6);

    vector<int> stack;
    int *visited = (int *)malloc(8 * sizeof(int));
    topo(g, 0, visited, &stack);
    print_vi(stack);

    return 0;
}
