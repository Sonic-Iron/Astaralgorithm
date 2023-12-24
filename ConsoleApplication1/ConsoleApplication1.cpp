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



size_t idx2d(const size_t cols, const size_t x, const size_t y)
{

	return (cols * y) + x;
}

struct node
{
	int ID;
	int type;
	//std::array<float, DIR_COUNT> edges {};
};

std::vector<node> create_area(const char area_type, const int area_side_length)
{

	std::vector<node> nodes;
	//nodes.reserve(area_side_length * area_side_length); //reserves uninitialised memory space of node type (expects nodes)
	
	/*
	nodes.push_back({ 1,1 }); //can do this because the vector expects node type
	nodes.push_back({ 2,2 });
	nodes.erase(nodes.begin()); //gets rid of the 0th element, reallocates the positions of all other elements so is inefficient.
	nodes.erase(nodes.begin()); //same thing but for the second element created as the second was moved to the 0th posiiton
	*/
	for (int i = 0; i < (area_side_length * area_side_length); i++)
	{
		nodes.push_back({ i, 0 });
	}
	//std::cout << nodes.size() << ' ' << nodes.at(0).ID << std::endl; //gets '1' as the first pushback is 1 for the ID. Checks my code is working

	return nodes;

}


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