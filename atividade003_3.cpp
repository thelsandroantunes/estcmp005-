#include <iostream>

float FtoC(float f){
    return (f-32)/1.8;
}
int main(){
	int fah = 0;

	std::cin >> fah;
	std::cout << "\n"<<fah<<"° F = " << FtoC(fah) <<"° C" << std::endl;
    
    return 0;
}
