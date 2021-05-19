#include <stdio.h>

int main() {

	int low, high;

	scanf("%i%i", &low, &high);
	
	printf("\n");
	if(low > high){
		printf(" %i", low);
	}else if (low < high){
		printf("%i", high);
	}else{
		printf("erro");
	}
	return 0;
}

