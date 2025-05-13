#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Prototipação das funções
void De_bi();
void bi_de();
void bi_octal();
void de_octal();
void bi_hexa();
void de_hexa();
void ascii_de();

int main() {
    int n;
    bool parar = false;

    while (!parar) {
        printf("\n===== Calculadora Multibase =====\n");
        printf("0 - Parar o programa.\n");
        printf("1 - Decimal para binário\n");
        printf("2 - Binário para decimal\n");
        printf("3 - Binário para octal\n");
        printf("4 - Decimal para octal\n");
        printf("5 - Binário para hexadecimal\n");
        printf("6 - Decimal para hexadecimal\n");
        printf("7 - Texto para códigos ASCII decimais\n");
        printf("Escolha uma opção: ");
        scanf("%d", &n);
        getchar(); 

        switch (n) {
            case 0: parar = true; break;
            case 1: De_bi(); break;
            case 2: bi_de(); break;
            case 3: bi_octal(); break;
            case 4: de_octal(); break;
            case 5: bi_hexa(); break;
            case 6: de_hexa(); break;
            case 7: ascii_de(); break;
            default: printf("Opção inválida!\n");
        }
    }
}

// Decimal para binário
void De_bi() {
    int decimal, binario[16];
    int i = 0;

    printf("Digite um número decimal (até 32767): ");
    scanf("%d", &decimal);
    getchar();

    if (decimal == 0) {
        printf("Binário: 0\n");
        return;
    }

    while (decimal > 0) {
        binario[i++] = decimal % 2;
        decimal /= 2;
    }

    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

// Binário para decimal
void bi_de() {
    char binario[17];
    int decimal = 0;

    printf("Digite um número binário (até 16 bits): ");
    fgets(binario, sizeof(binario), stdin);

    size_t len = strlen(binario);
    if (binario[len - 1] == '\n') {
        binario[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++) {
        if (binario[i] == '0' || binario[i] == '1') {
            decimal = decimal * 2 + (binario[i] - '0');
        } else {
            printf("Caractere inválido: %c\n", binario[i]);
            return;
        }
    }

    printf("Decimal: %d\n", decimal);
}

// Binário para octal
void bi_octal() {
    char binario[17], binario_completo[20] = "";
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
            printf("Entrada inválida.\n");
            return;
        }
    }

    int padding = (3 - (len % 3)) % 3;
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

// Decimal para octal
void de_octal() {
    int num, i = 0;
    char octal[20];

    printf("Digite um número decimal (até 32767): ");
    scanf("%d", &num);
    getchar();

    if (num == 0) {
        printf("Octal: 0\n");
        return;
    }

    while (num > 0) {
        octal[i++] = (num % 8) + '0';
        num /= 8;
    }

    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", octal[j]);
    }
    printf("\n");
}

// Binário para hexadecimal
void bi_hexa() {
    char binario[21], binario_completo[25] = "";
    int len, i, j, valor;

    printf("Digite um número binário (até 20 bits): ");
    fgets(binario, sizeof(binario), stdin);

    len = strlen(binario);
    if (binario[len - 1] == '\n') {
        binario[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            printf("Entrada inválida.\n");
            return;
        }
    }

    int padding = (4 - (len % 4)) % 4;
    for (i = 0; i < padding; i++) {
        strcat(binario_completo, "0");
    }
    strcat(binario_completo, binario);
    len = strlen(binario_completo);

    printf("Hexadecimal: ");
    for (i = 0; i < len; i += 4) {
        valor = 0;
        for (j = 0; j < 4; j++) {
            if (binario_completo[i + j] == '1') {
                valor += 1 << (3 - j);
            }
        }
        if (valor < 10)
            printf("%d", valor);
        else
            printf("%c", 'A' + (valor - 10));
    }
    printf("\n");
}

// Decimal para hexadecimal
void de_hexa() {
    int decimal, resto, i = 0;
    char hexa[20];

    printf("Digite um número decimal (até 32767): ");
    scanf("%d", &decimal);
    getchar();

    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (decimal > 0) {
        resto = decimal % 16;
        hexa[i++] = (resto < 10) ? resto + '0' : resto - 10 + 'A';
        decimal /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

// Texto para ASCII decimal
void ascii_de() {
    char texto[500];

    printf("Digite uma palavra ou frase: ");
    fgets(texto, sizeof(texto), stdin);

    size_t len = strlen(texto);
    if (texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }

    printf("Valores ASCII decimais:\n");
    for (int i = 0; texto[i] != '\0'; i++) {
        printf("'%c' = %d\n", texto[i], (int)texto[i]);
    }
}