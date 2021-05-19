#include <stdio.h>

int toCelsius(int fahrenheit) {
    return 5 * (fahrenheit - 32) / 9;
}

int main (){
    
    int fahrenheit = 0;
    scanf("%d",&fahrenheit);

    printf("%d °C", toCelsius(fahrenheit));

    return 0;
}
