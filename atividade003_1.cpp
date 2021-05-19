#include <iostream>

int main() {
	int low = 0, high = 0;

	std::cin >> low;
	std::cin >> high;


	for (int i = low + 1; i < high; i++) std::cout << i << " ";
}
