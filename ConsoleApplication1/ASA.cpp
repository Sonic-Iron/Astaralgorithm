
#include<iostream>
#include<map>
#include<vector>


struct vertex {
	int ID;
	std::vector<std::pair<vertex, float>> edges;
	vertex* pre_node; //shared_ptr ?
	bool explored;
};

void AddNode() {

}

void AddEdge(vertex node1, vertex node2, float cost) {

}

int main() {
	std::vector<vertex> graph;
	
}