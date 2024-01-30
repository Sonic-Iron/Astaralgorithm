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
	const int location_index;
	int pre_index;
	const int type;
	const char symbol;
	bool visited = false;
	std::array<std::pair<int,int>, DIR_COUNT> edges;
};

int idx2d(const int current_loc, const int delta_x, const int delta_y, const int length_x, const int length_y) //returns the position of a node converted from a 2d space to a 1d vector, y is positive in the positive direction. North is positive
{
	if(current_loc % length_y + delta_x < 0 || current_loc % length_y + delta_x > length_x) 
	{ //check for off the sides
		return -1;
	}
	if(current_loc + length_x * delta_y < 0 || current_loc + length_x * delta_y > length_x * length_y)
	{ //check for off the top/bottom
		return -1;
	}// Should I check for out of bounds here or use a try/catch?
	return (current_loc + (length_x * delta_y) + delta_x);
}

int idx2d(const int current_loc, const int direction, const int length_x, const int length_y)
{
	switch (direction)
	{
	case 0:
		return idx2d(current_loc, 0, 1, length_x, length_y);
		//break here? and after all other returns?
	case 1:
		return idx2d(current_loc, 1, 1, length_x, length_y);
	case 2:
		return idx2d(current_loc, 1, 0, length_x, length_y);
	case 3:
		return idx2d(current_loc, 1, -1, length_x, length_y);
	case 4:
		return idx2d(current_loc, 0, -1, length_x, length_y);
	case 5:
		return idx2d(current_loc, -1, -1, length_x, length_y);
	case 6:
		return idx2d(current_loc, -1, 0, length_x, length_y);
	case 7:
		return idx2d(current_loc, -1, 1, length_x, length_y);
	default:
		return current_loc;
	}
}

int calculate_edge_cost(const int type1, const int type2)
{
	return 1; //will update this later, all types of path will have the same length for now
}

std::vector<node> create_edges(std::vector<node>& nodes, const int length_x, const int length_y) //use inline here as it could be put into the create_area function?, it doesn't return anything
{
	for (int location = 0; location < nodes.size(); location++)
	{
		std::cout << location << std::endl;
		for (int direction = 0; direction < 8; direction++)
		{
			int new_location = idx2d(location, direction);
			if (new_location == -1)
			{
				return std::vector<node>(); //returns an anonymous object? there is no lvalue here so is it safe?
			}
			nodes.at(location).edges.at(location, direction, length_x, length_y) = (calculate_edge_cost(nodes[location].type, nodes[new_location].type), new_location);
		}
	}
	return nodes; //since nodes is a reference do I have to return it here? I could have a void function as all this does is modify the nodes vector?
}

std::vector<node> create_area(const char area_type, const int length_x, const int length_y)
{
	std::vector<node> nodes;
	nodes.reserve(length_x * length_y); //reserves uninitialised memory space of node type (expects nodes)

	for (int i = 0; i < (length_x * length_y); i++)
	{
		nodes.push_back({i, -1, 0, '.', {}}); //TODO: sort this out lol
		//create the areas here I guess
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
	const int num_people {10};

	std::cout << "Type of area (r for rural, s for suburban, and u for urban)" << std::endl;
	std::cin >> area_type;
	std::cout << "Size of the area sides x,y with two integers" << std::endl;
	std::cin >> length_x >> length_y;
	std::cout << area_type << length_x << length_y << std::endl;
	std::vector<node> nodes = create_area(area_type, length_x, length_y);

	return 0;
}


// I know that all the graph creation stuff should be in a header file just it's easier to work on here for now