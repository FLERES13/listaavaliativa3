#include <stdio.h>

int main() {
    int listaEmValorDecimal[30];
    int valorEmDecimal = 0;
    int cont = 0;
    char romano[30];
    char caractere;
    int p = 0;

    do {
        caractere = getchar();
        romano[cont] = caractere;

        switch (caractere) {
            case 'I':
                listaEmValorDecimal[cont] = 1;
                break;
            case 'V':
                listaEmValorDecimal[cont] = 5;
                break;
            case 'X':
                listaEmValorDecimal[cont] = 10;
                break;
            case 'L':
                listaEmValorDecimal[cont] = 50;
                break;
            case 'C':
                listaEmValorDecimal[cont] = 100;
                break;
            case 'D':
                listaEmValorDecimal[cont] = 500;
                break;
            case 'M':
                listaEmValorDecimal[cont] = 1000;
                break;
            default:
                break;
        }

        cont++;
    } while (caractere != '\n');

    romano[cont - 1] = '\0';

    for (int i = 0; i < (cont - 1); i++) {
        if (i > 0 && listaEmValorDecimal[i] > listaEmValorDecimal[i - 1]) {
            valorEmDecimal += listaEmValorDecimal[i] - (2 * listaEmValorDecimal[i - 1]);
        } else {
            valorEmDecimal += listaEmValorDecimal[i];
        }
    }

    p = 0;
    int bina = valorEmDecimal;
    int dividirpor2 = 2;
    int binario[30];
    while (bina >= dividirpor2) {
        binario[p] = bina % dividirpor2;
        bina = bina / dividirpor2;
        p++;
    }
    binario[p] = bina;
    p++;
    printf("%s na base 2: ", romano);
    for (int i = p - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
    printf("\n");

    p = 0;

    int hexa = valorEmDecimal;
    char hexadecimal[30];
    int divisorPor16 = 16;

do {
    int resto = hexa % divisorPor16;
    hexadecimal[p] = (resto < 10) ? (resto + '0') : (resto - 10 + 'a');
    hexa /= divisorPor16;
    p++;
} while (hexa > 0);
    printf("%s na base 10: %d\n", romano, valorEmDecimal);
    
    printf("%s na base 16: ", romano);
    for (int i = p - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");

    return 0;
}