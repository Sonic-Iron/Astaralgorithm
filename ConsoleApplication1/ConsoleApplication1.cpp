#include <array>
#include <iostream>
#include <map>
#include <vector>


#define DIR_N 0
#define DIR_NE 1
#define DIR_E 2
#define DIR_SE 3
#define DIR_S 4
#define DIR_SW 5
#define DIR_W 6
#define DIR_NW 7
#define DIR_COUNT 8

struct node
{
	const int ID;
	const int type;
	const char symbol;
	std::array<float, DIR_COUNT> edges;
};


int idx2d(const int current_ID, const int delta_x, const int delta_y) //returns the position of a node converted from a 2d space to a 1d vector
{
	
	return 1;
}

std::vector<node> create_edges(std::vector<node>& nodes, const int length_x, const int length_y) //use inline here as it could be put into the create_area function, it doesn't return anything
{
	for (node node : nodes)
	{

	}
	return nodes;
}

std::vector<node> create_area(const char area_type, const int length_x, const int length_y)
{
	std::vector<node> nodes;
	nodes.reserve(length_x * length_y); //reserves uninitialised memory space of node type (expects nodes)

	/*
	nodes.push_back({ 1,1 }); //can do this because the vector expects node type
	nodes.push_back({ 2,2 });
	nodes.erase(nodes.begin()); //gets rid of the 0th element, reallocates the positions of all other elements so is inefficient.
	nodes.erase(nodes.begin()); //same thing but for the second element created as the second was moved to the 0th posiiton
	*/
	//std::cout << nodes.capacity() << nodes.size() << std::endl;
	for (int i = 0; i < (length_x * length_y); i++)
	{
		nodes.push_back({ i, 0, {} });
	}
	//std::cout << nodes.capacity() << nodes.size() << std::endl; These are different and reflect the fact that the vector is now filled.
	nodes = create_edges(nodes, length_x, length_y); //do i need to return nodes here?

	return nodes;

}


void run_ASA()
{

}

int main()
{
	char area_type;
	int length_x;
	int length_y;
	const int num_people = 10;

	std::cout << "Type of area (r for rural, s for suburban, and u for urban)" << std::endl;
	std::cin >> area_type;
	std::cout << "Size of the area sides x,y with two integers, seperated by a space. Example: 1 1" << std::endl;
	std::cin >> length_x >> length_y;
	std::vector<node> nodes = create_area(area_type, length_x, length_y);
}