
#include <iostream>
#include <vector>
using namespace std;

struct DirectedGraphNode {
	int value;
	DirectedGraphNode *next;
};

struct Edge {
	int source;
	int destination;
};

struct DirectedGraph {
	vector<vector<int>> adjacency;
	DirectedGraph(vector<Edge> const& edges, int nodesNumber) {}
};