#include "palindrome.h"

/**
 * is_palindrome - checks wether an integer is a palindrome or not
 * @n: number to check
 *
 * Return: 1 if n is a palindrome ; 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    int first, last;
    unsigned long mod, div;
    int length = get_length(n);
    int i = 0, shift = 1;

    for (i = 0 ; i < length / 2 ; i++)
    {
        /* Getting first and last digits */
        mod = raise(10, shift);
        div = raise(10, length - shift);

        first = (n / div) % 10;
        last = (n % mod) / raise(10, shift -1);

        printf("First: %i ; Last: %i\n\n", first, last);

        /* Comparing them */
        if (first != last)
            return 0;

        shift++;
    }

    return 1;
}

/**
 * get_length - gets the number of digits of an integer
 * @n: number to check
 *
 * Return: length of n
 */
int get_length(unsigned long n)
{
    int length = 0;

    while (n != 0)
    {
        n /= 10;
        length++;
    }

    return (length);
}

/**
 * raise - raises a number to a given power
 * @value: number to raise
 * @power: power to use
 *
 * Return: result
 */
unsigned long raise(unsigned long value, int power)
{
    int i = 1;
    int base = value;

    if (!power)
        return 1;

    for (i = 1 ; i < power ; i++)
        value *= base;

    return (value);
}
