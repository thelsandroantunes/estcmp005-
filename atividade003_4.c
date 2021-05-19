#include <stdio.h>

int main(){

    double nota1, nota2, nota3, nota4, media;
    nota1 = nota2  =  nota3 = nota4 = media = 0;

    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    scanf("%lf", &nota3);
    scanf("%lf", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    if(media == 6.0){
        printf("Aprovado.");
    }else{
        printf("Reprovado.");
    }

    return 0;
}
