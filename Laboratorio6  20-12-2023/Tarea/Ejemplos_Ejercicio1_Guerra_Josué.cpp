#include <stdio.h>
#include <conio.h>

void clrscr() {
    int __cdecl system(const char * cls);
}

void putch(char ch) {
    putchar(ch);
}

char* cgets(char *str, int size) {
    return fgets(str, size, stdin);
}

int main() {
    clrscr();

    putch('H');
    putch('O');
    putch('L');
    putch('A');
    putch('X');
    putch('D');
    putch(',');

    printf(" Que la fuerza te acompañe!\n");

    char input[50];
    printf("Ingresa un texto: ");
    cgets(input, sizeof(input)); // Utiliza fgets en lugar de gets

    printf("Tu ingresaste: %s\n", input);

    getch(); // Espera una tecla

    return 0;
}



