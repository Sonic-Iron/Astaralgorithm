#include<iostream>
#include<map>
#include<vector>


struct edge {
	int nodeTo;
	float cost;
};

struct node {
	int ID;
	std::string symbol;
	std::vector<edge>;
};

std::string create_area(std::string& area, const std::string area_type, const int area_size) {
	std::array<std::array<std::string, area_size>, area_size> area;
	if (area_type = 'r') {

	}
	else if (area_type = 'h') {

	}
	else if (area_type = 'u') {

	}
	else {
		return '0';
	}
}


void run_ASA() {

}

int pickpoint()

int main() {
	string area_type;
	int area_size;
	std::cout << "Type of area" << std::cout;
	std::cin >> area_type;
	std::cout << "Size of area in integer" << std::cout;
	std::cin >> area_size;
	area = create_area(area, area_type, area_size);
	if (area = '0') {
		return 1;
	}
	else {
		run_ASA(num_people, area);
	}
	
}