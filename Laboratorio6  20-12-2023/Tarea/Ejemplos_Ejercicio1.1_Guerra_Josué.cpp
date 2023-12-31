#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdarg.h>

void custom_clrscr() {
    int __cdecl system(const char * cls);
}

void custom_cscanf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vscanf(format, args);
    va_end(args);
}

void custom_cprintf(int text_color, int background_color, const char *format, ...) {
    void textcolor (int YELLOW);
    void textbackground(int BLUE);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

}

int main() {
    custom_clrscr();

    printf("INGRESA UN NUMERO: ");
    
    int num;
    custom_cscanf("%d", &num);

    custom_cprintf(YELLOW, BLUE, "Has ingresado el: %d\n", num);

    printf("Presiona una tecla para salir...");

    getch(); // Esperar a que se presione una tecla
    
    return 0;
}

