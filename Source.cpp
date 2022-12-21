#include <iostream>
#include <vector>
#include "Vector.h"

template <typename T>
void print(T& container){
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void contfill(T& container) {
	for (size_t i = 0; i < container.size(); i++)
	{
		container[i] = rand() % 100;
	}
}

int main() {
	srand(time(NULL));

	Vector<int> vect(10);
	
	contfill(vect);
	print(vect);

	// write your own tests here

	print(vect);
}
