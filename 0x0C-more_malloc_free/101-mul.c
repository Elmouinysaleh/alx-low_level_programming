#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * is_digit_string - checks if a string only contains digits
 * @str: the string to check
 *
 * Return: 1 if the string only contains digits, 0 otherwise
 */
int is_digit_string(const char *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/**
 * multiply - multiplies two positive numbers
 * @a: the first number to multiply
 * @b: the second number to multiply
 *
 * Return: the product of the two numbers
 */
int multiply(int a, int b)
{
    return a * b;
}

/**
 * print_int - prints an integer
 * @n: the integer to print
 */
void print_int(int n)
{
    if (n < 0) {
        _putchar('-');
        n = -n;
    }
    if (n / 10) {
        print_int(n / 10);
    }
    _putchar(n % 10 + '0');
}

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: the arguments array
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }
    char *num1_str = malloc(strlen(argv[1]) + 1);
    char *num2_str = malloc(strlen(argv[2]) + 1);
    if (num1_str == NULL || num2_str == NULL) {
        printf("Error\n");
        return 98;
    }
    strcpy(num1_str, argv[1]);
    strcpy(num2_str, argv[2]);
    if (!is_digit_string(num1_str) || !is_digit_string(num2_str)) {
        printf("Error\n");
        free(num1_str);
        free(num2_str);
        return 98;
    }
    int num1 = atoi(num1_str);
    int num2 = atoi(num2_str);
    int result = multiply(num1, num2);
    print_int(result);
    _putchar('\n');
    free(num1_str);
    free(num2_str);
    return 0;
}
