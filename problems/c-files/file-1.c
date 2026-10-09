#include <stdio.h>

int main(void){
// Read two integers and print their sum, difference, product, and quotient.
// int num1,num2;
// printf("Enter num1: ");
// scanf("%d",&num1);
// printf("Enter num2: ");
// scanf("%d",&num2);
// printf("Sum: %d\n",num1+num2);
// printf("Difference: %d\n",num1-num2);
// printf("Product: %d\n",num1*num2);
// printf("Quotient: %d",num1/num2);

// Convert a temperature from Celsius to Fahrenheit.
float val, cel = 0.0f, fah = 0.0f; // Good practice: Initialize variables to 0
    char tem;

    printf("Enter value: ");
    scanf("%f", &val);

    printf("For output celsius type c or for fahrenheit type f: ");
    // FIX 1: Added a leading space before %c to clear the leftover newline character in the buffer
    scanf(" %c", &tem); 

    if (tem == 'c' || tem == 'C') {
        // FIX 2: Used 5.0 / 9.0 (floating-point division) instead of 5 / 9 (which equals 0)
        cel = (val - 32) * (5.0f / 9.0f);
        printf("Celsius: %f\n", cel);
    }
    else if (tem == 'f' || tem == 'F') {
        // FIX 3: Used 9.0 / 5.0 (floating-point division) instead of 9 / 5 (which equals 1)
        fah = (val * (9.0f / 5.0f)) + 32;
        printf("Fahrenheit: %f\n", fah);
    }
    else {
        printf("Invalid input choice.\n");
    }

    return 0;
}