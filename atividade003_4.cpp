#include <iostream>
 
int main(){
	float nota1, nota2, nota3, nota4, media;    
	std::cin >> nota1 >> nota2 >> nota3 >> nota4;    
	media = (nota1 + nota2+ nota3 + nota4) / 4;
	if(media > 6.0) std::cout << "Aprovado " << std::endl;
	else std::cout << "Reprovado "<< std::endl;
	
    return 0;
}
