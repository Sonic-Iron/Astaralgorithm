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



int idx2d(const int current_ID;  const int row_size, const int x, const int y) //returns the position of a node converted from a 2d space to a 1d vector
{
	if (y - 1 < 0 || y + 1 > row_size) 
	{
		return -1;
	}
	if (x - 1 < 0 || x + 1 > row_size)
	{
		return -1;
	}

	// add here the new ID
}

struct node
{
	const int ID;
	const int type;
	const char symbol;
	std::array<float, DIR_COUNT> edges;
};

std::vector<node> create_edges(std::vector<node> nodes) //use inline here as it could be put into the create_area function, it doesn't return anything
{ 
	for (node node : nodes)
	{
		
	}
	return nodes;
}

std::vector<node> create_area(const char area_type, const int area_side_length)
{

	std::vector<node> nodes;
	nodes.reserve(area_side_length * area_side_length); //reserves uninitialised memory space of node type (expects nodes)
	
	/*
	nodes.push_back({ 1,1 }); //can do this because the vector expects node type
	nodes.push_back({ 2,2 });
	nodes.erase(nodes.begin()); //gets rid of the 0th element, reallocates the positions of all other elements so is inefficient.
	nodes.erase(nodes.begin()); //same thing but for the second element created as the second was moved to the 0th posiiton
	*/
	//std::cout << nodes.capacity() << nodes.size() << std::endl; Returns 90, this is because of the reserve function above. 
	for (int i = 0; i < (area_side_length * area_side_length); i++)
	{
		nodes.push_back({ i, 0, {} });
	}
	//std::cout << nodes.capacity() << nodes.size() << std::endl; Returns 99 

	return nodes;

}//This is a comment


void run_ASA()
{

}

int main()
{
	char area_type;
	int area_size;
	const int num_people = 10;

	std::cout << "Type of area (r for rural, s for suburban, and u for urban)" << std::endl;
	std::cin >> area_type;
	std::cout << "Size of the area in intergers" << std::endl;
	std::cin >> area_size;
	std::vector<node> nodes = create_area(area_type, area_size);	
}