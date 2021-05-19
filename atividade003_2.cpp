#include <iostream>

int main() {
	int low = 0, high = 0;

	std::cin >> low >> high;
	std::cout << "\n";
	if (low > high) std::cout << low;
	else if (low < high) std::cout << high;
	else std::cout << "Erro";
	
	
}
