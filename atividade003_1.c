#include <stdio.h>
int main(){
	int low, high, i;
	scanf("%d %d", &low, &high);
	
	low = low + 1;
	while (low<high)
	{    
		printf("%d ", low);
		++low;
	}
	
	return 0;
}
