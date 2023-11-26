#include<iostream>
#include<map>
#include<vector>



struct vertex {
	int ID;
	struct edge {
		int destination;
		float cost;
	}
	std::vector<edge> edges;
	bool explored = false;
};

static void AddNode(std::vector graph, int nodeID) {
	std::unique_ptr<vertex> node = 
	node.ID = nodeID;
	graph.push_back(node);
}

static void AddEdge(std::vector graph, vertex node1, vertex node2, float cost) {
	
}

int main() {
	int number_nodes = 0;
	std::vector<vertex> graph;
	
	AddNode(graph, ++number_nodes);

	std::cout << *graph[0].ID << std::endl;


	
}