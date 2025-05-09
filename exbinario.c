#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {

}

void De_bi(){
    int decimal, binario[16];
    int i = 0;

    printf("Digite um número decimal(limite de 16 bits ou seja entre -32.768 e 32.767): ");
    scanf("%d", &decimal);

    if (decimal == 0) {
        printf("Binário: 0\n");
        return 0;
    }

    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }

    printf("\n");

    return 0;
}

void bi_de(){
    char binario[16];
    int decimal = 0;
    int tamanho = 0;

    printf("Digite um número binário(limite de 16 bits ou seja um limite de numeros de 16 entre 0 e 1): ");
    fgets(binario, sizeof(binario), stdin);

    tamanho = strlen(binario);
    if (binario[tamanho - 1] == '\n') {
        binario[tamanho - 1] = '\0';
        tamanho--;
    }
    
    for (int i = 0; i < tamanho; i++){
        if (binario[i] == '1' || binario[i] == '0'){
            decimal = decimal * 2 + (binario[i] - '0');
        } else {
            printf("Entrada inválida. Por favor, digite apenas 0 ou 1: %c\n"), binario[i];
            return 1;
        }
    }
    
    printf("Decimal: %d\n", decimal);

    return 0;
}


void bi_octal() {
    char binario[16]; 
    int len, i, j, valor;

    printf("Digite um número binário (até 15 bits): ");
    fgets(binario, sizeof(binario), stdin);

    len = strlen(binario);
    if (binario[len - 1] == '\n') {
        binario[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            printf("Entrada inválida. Apenas 0 e 1 são permitidos.\n");
            return;
        }
    }

    int padding = (3 - (len % 3)) % 3;
    char binario_completo[20] = "";
    for (i = 0; i < padding; i++) {
        strcat(binario_completo, "0");
    }
    strcat(binario_completo, binario);
    len = strlen(binario_completo);

    printf("Octal: ");
    for (i = 0; i < len; i += 3) {
        valor = 0;
        for (j = 0; j < 3; j++) {
            if (binario_completo[i + j] == '1') {
                valor += 1 << (2 - j); 
            }
        }
        printf("%d", valor);
    }

    printf("\n");
}

void octal_bi(){
    char octal[20];

    printf("Digite um numero em octal lembrando que octal é a juncao de 3 bits (até 18 bits) ou seja 6 combinacoes: ");
    fgets(octal, sizeof(octal), stdin);

    size_t len = strlen(octal);
    if (octal[len - 1] == '\n') {
        octal[len -1] = '\0';
    }
    
    printf("Binário  ");

    for (int i = 0; i < octal[i]; i++){
        switch (octal[i]){
            case '0': printf("000"); break;
            case '1': printf("001"); break;
            case '2': printf("010"); break;
            case '3': printf("011"); break;
            case '4': printf("100"); break;
            case '5': printf("101"); break;
            case '6': printf("110"); break;
            case '7': printf("111"); break;
        
            default:
            printf("\n Caractere inválido: %c\n", octal[i]);
            return;
        }
    }
    printf("\n");
}





