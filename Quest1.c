#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isNumeroRomanoValido(char* numeroRomano) {
    int comprimento = strlen(numeroRomano);

    for (int i = 0; i < comprimento; i++) {
        char c = numeroRomano[i];
        if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M') {
            return false;
        }
    }
    return true;
}
int valorRomano(char romano) {
    switch (romano) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanoParaDecimal(char* numeroRomano) {
    int resultado = 0;
    int comprimento = strlen(numeroRomano);

    for (int i = 0; i < comprimento; i++) {
        int valorAtual = valorRomano(numeroRomano[i]);
        int proximoValor = (i < comprimento - 1) ? valorRomano(numeroRomano[i + 1]) : 0;

        if (valorAtual < proximoValor) {
            resultado += proximoValor - valorAtual;
            i++;  
        } else {
            resultado += valorAtual;
        }
    }
    return resultado;
}
long decimalParaBinario(int decimal) {
    long binario = 0, fator = 1;

    while (decimal > 0) {
        binario += (decimal % 2) * fator;
        decimal /= 2;
        fator *= 10;
    }
    return binario;
}

int main() {
    char numeroRomano[13];

    scanf("%s", numeroRomano);

    int decimal = romanoParaDecimal(numeroRomano);
    
    long binario = decimalParaBinario(decimal);
    
    printf("%s na base 2: %ld\n", numeroRomano, binario);
    printf("%s na base 10: %d\n", numeroRomano, decimal);
    printf("%s na base 16: %x\n", numeroRomano, decimal);

    return 0;
}
