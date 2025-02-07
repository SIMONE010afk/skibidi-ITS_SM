#include <stdio.h>
#include <math.h> //needed to use the function pow

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float divi(int a, int b) {
    if (b == 0) {
        printf("Errore: divisione per zero!\n");
        return 0.0;
    }
    return (float)a / b;
}

int mod(int a, int b) {
    if (b == 0) {
        printf("Errore: modulo per zero!\n");
        return 0;
    }
    return a % b;
}

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

/*
void test_all_operations(int arr[], int size) {
    printf("Test delle operazioni sui numeri {");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("}:\n");

    for (int i = 0; i < size - 1; i++) {
        printf("%d + %d = %d\n", arr[i], arr[i+1], add(arr[i], arr[i+1]));
        printf("%d - %d = %d\n", arr[i], arr[i+1], sub(arr[i], arr[i+1]));
        printf("%d * %d = %d\n", arr[i], arr[i+1], mul(arr[i], arr[i+1]));
        printf("%d / %d = %.2f\n", arr[i], arr[i+1], divi(arr[i], arr[i+1]));
        printf("%d %% %d = %d\n", arr[i], arr[i+1], mod(arr[i], arr[i+1]));
        printf("%d ^ %d = %d\n", arr[i], arr[i+1], power(arr[i], arr[i+1]));
    }
}
*/
void test_all_operations(int arr[], int size) {
    printf("Testiamo con i numeri dati:\n");
    
    for (int i = 0; i < size - 1; i++) {  // Iterate over consecutive pairs
        int num1 = arr[i];
        int num2 = arr[i + 1];

        printf("\nStai testando con %d e %d:\n", num1, num2);
        printf("%d + %d = %d\n", num1, num2, add(num1, num2));
        printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
        printf("%d * %d = %d\n", num1, num2, mul(num1, num2));

        if (num2 != 0) {
            printf("%d / %d = %.2f\n", num1, num2, divi(num1, num2));
            printf("%d %% %d = %d\n", num1, num2, mod(num1, num2));
        } else {
            printf("Divisione e modulo non sono permesse per 0.\n");
        }

        printf("%d ^ %d = %d\n", num1, num2, power(num1, num2));
    }
}