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
	std::array<float, DIR_COUNT> edges;
};


int idx2d(const int current_ID, const int delta_x, const int delta_y, const int length_x, const int length_y) //returns the position of a node converted from a 2d space to a 1d vector
{
	if(current_ID % length_y - delta_x < 0 || current_ID % length_y + delta_x > length_x) { //off the sides
		return current_ID;
	}
	if (current_ID + length_x * delta_y > 0 || current_ID - length_x * delta_y > length_x * length_y) {//off the top/bottom
		return current_ID;
	}
	return current_ID + length_x * delta_y + delta_x;
}

std::vector<node> create_edges(std::vector<node>& nodes, const int length_x, const int length_y) //use inline here as it could be put into the create_area function?, it doesn't return anything
{
	for (node node : nodes)
	{
		if()
		{

		}
	}
	return nodes;
}

std::vector<node> create_area(const char area_type, const int length_x, const int length_y)
{
	std::vector<node> nodes;
	nodes.reserve(length_x * length_y); //reserves uninitialised memory space of node type (expects nodes)

	for (int i = 0; i < (length_x * length_y); i++)
	{
		nodes.push_back({ i, 0, {}});
	}
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