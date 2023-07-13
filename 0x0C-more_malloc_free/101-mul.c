#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string only contains digits
int is_digit_string(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to multiply two positive numbers
int multiply(int a, int b) {
    return a * b;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }
    // Allocate memory for the input strings
    char *num1_str = (char *) malloc(strlen(argv[1]) + 1);
    char *num2_str = (char *) malloc(strlen(argv[2]) + 1);
    if (num1_str == NULL || num2_str == NULL) {
        printf("Error\n");
        return 98;
    }
    // Copy the input strings to the allocated memory
    strcpy(num1_str, argv[1]);
    strcpy(num2_str, argv[2]);
    // Check if the input strings are composed of digits
    if (!is_digit_string(num1_str) || !is_digit_string(num2_str)) {
        printf("Error\n");
        free(num1_str);
        free(num2_str);
        return 98;
    }
    // Convert the input strings to integers
    int num1 = atoi(num1_str);
    int num2 = atoi(num2_str);
    // Multiply the numbers and print the result
    int result = multiply(num1, num2);
    printf("%d\n", result);
    // Free the allocated memory
    free(num1_str);
    free(num2_str);
    return 0;
}
