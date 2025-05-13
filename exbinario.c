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

    printf("Digite um número binário(limite de 16 bits ou seja um limite de numeros de 16, entre 0 e 1): ");
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
    printf("\n");
    return 0;
}


void bi_octal() {
    char binario[16]; 
    int len, i, j, valor;

    printf("Digite um número binário(limite de 15 bits ou seja um limite de numeros de 15, entre 0 e 1): ");
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
    return 0;
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
    return 0;
}

void bi_hexa(){
    char binario[21];

    printf("Digite um número binário(limite de 20 bits ou seja um limite de numeros de 20, entre 0 e 1): ");
    fgets(binario, sizeof(binario), stdin);

    size_t len = strlen(binario);
    if (binario[len - 1] == '\n') {
        binario[len -1] = '\0';
    }
    
    printf("Binário digitado: \n ");

    for(int i = 0; i < 21; i++){
        printf("%c",binario[i]);
    }


    for (int i = 0; i < binario[i]; i++){
        switch (binario[i]){
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': printf("1010"); break;
            case 'B': printf("1011"); break;
            case 'C': printf("1100"); break;
            case 'D': printf("1101"); break;
            case 'E': printf("1110"); break;
            case 'F': printf("1111"); break;
        
            default:
            printf("\n Caractere inválido: %c\n", binario[i]);
            return;
        }
    }
    printf("\n");
    return 0;
}


void de_hexa(){
    int decimal = 0, i =0, de = 0 resto = 0;
    char hexa[21];

    printf("Digite um numero decimal para converter em hexadecimal(lembrando que o limite de numeros é de 20): \n");
    scanf("%d", &decimal);

    de = decimal;

    while(decimal > 0){
        resto = decimal % 16;

        if(resto < 10){
            hexa[i] = resto + '0';
        } else{
            hexa[i] = resto - 10 + 'A';
        }

        decimal = decimal / 16;
        i++;
    }
    
    printf("O numero que voce digitou em decimal é: %d\n Ja o numero convertido para hexadecimal é: ", de);
    for(int j = i; j < 1; j--){
        printf("%c", hexa[j]);
    }
    printf("\n");
    return 0;
}

void ascii_de() {
    char texto[100];

    printf("Digite uma palavra ou frase: ");
    fgets(texto, sizeof(texto), stdin);

    // Remover o '\n' do final se existir
    size_t len = strlen(texto);
    if (texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
        len--;
    }

    printf("Valores ASCII decimais:\n");
    for (int i = 0; texto[i] != '\0'; i++) {
        printf("'%c' = %d\n", texto[i], (int)texto[i]);
    }
}
/*/Atividades

Decimal para binário
Binário para decimal

Binário para octal
Decimal para octal

Binário para hexadecimal 
Decimal para hexadecimal 

Pesquisar tabela ASCII 

Quando escrever uma palavra ou frase, o valor deve ser convertido para o seu valor decimal correspondente da tabela ASCII
/*/


