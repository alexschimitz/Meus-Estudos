#include <stdio.h>

int main()
{
    int idioma;
    printf("1 - PT-BR\n2 - EN\n3 - Japanese\n4 - Mandarin\n5 - Russian\n");
    scanf("%d", &idioma);
    if(idioma == 1) printf("Olá, Mundo!");//Portugues
    else if(idioma == 2) printf("Hello, World!\n");//Ingles
    else if(idioma == 3) printf("こんにちは、世界！\n");//Japones
    else if(idioma == 4) printf("你好，世界！\n");//Chines
    else if(idioma == 5) printf("Привет, мир!\n");//Russo
    else printf("Mundo, Olá!");//Padrão

    return 0;
}