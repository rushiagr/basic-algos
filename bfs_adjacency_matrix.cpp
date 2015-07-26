#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#include "utils/cpputils.h"

enum { WHITE, GRAY, BLACK };

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
        g[to][from] = 1;
    }

    vector<int> getEndsFrom(int startNode) {
        vector<int> returnList;
        for(int i=0; i<this->nodes; i++) {
            if(g[startNode][i] == 1)
                returnList.push_back(i);
        }
        return returnList;
    }
};

class ColouredGraph : public Graph {
    public:
    vector<int> colour;

    ColouredGraph(int nodes) : Graph(nodes) {
        for(int i=0; i<nodes; i++) {
            colour.push_back(WHITE);
        }
    }
};

void BFS(ColouredGraph g, int startNode) {
    queue<int> q;
    g.colour[startNode] = GRAY;
    q.push(startNode);

    while(!q.empty()) {
        cout<<"Element: "<<q.front()<<endl;
        g.colour[q.front()] = BLACK;
        vector<int> allIndices = g.getEndsFrom(q.front());
        for(int i=0; i<(int)allIndices.size(); i++) {
            if(g.colour[allIndices[i]] == WHITE) {
                g.colour[allIndices[i]] = GRAY;
                q.push(allIndices[i]);
            }
        }
        q.pop();
    }
}

int main() {
    ColouredGraph g = ColouredGraph(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(2, 4);
    BFS(g, 0);
//    print_vi(g.colour); //note: as copy of 'g' is passed, would have all 0s.

    return 0;
}
