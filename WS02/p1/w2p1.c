/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

// Imports
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // Standard IO
#include <stdlib.h> // Standard Library Functions

float cashFormat (int cents)
{
    float formatted = ((float) cents / 100);

    return formatted;
}

// Main Function
int main(void)
{
    /*
     * Steps:
     * 1. Print introduction text to user.
     * 2. Get input for amount of dollars from user.
     * 3. Convert to cents by multiplying by 100.
     * 4. Calculate number of toonies.
     * 5. Calculate number of loonies based on remaining money.
     * 6. Calculate number of quarters based on remaining money.
     * 7. Calculate the remainder of change the machine keeps if applicable.
     * 8. Output information to the user.
    */

    double userInput;  // The variable we will use to get the user's input.

    // Prompt user for information.
    printf("Change Maker Machine\n"
           "====================\n"
           "Enter dollars and cents amount to convert to coins: $");
    // Get user's input.
    scanf("%lf", &userInput);
    int cents = userInput * 100;

    printf("\n");

    int toonies = cents / 200; // Calculate number of toonies.
    cents %= 200; // Remove toonies from cents.
    printf("$2.00 Toonies  X %d (remaining: $%.2f)\n", toonies, cashFormat(cents));

    int loonies = cents / 100; // Calculate number of loonies.
    cents %= 100; // Remove loonies from remaining cents.
    printf("$1.00 Loonies  X %d (remaining: $%.2f)\n", loonies, cashFormat(cents));

    int quarters = cents / 25; // Calculate number of quarters.
    cents %= 25; // Remove quarters from remaining cents.
    printf("$0.25 Quarters X %d (remaining: $%.2f)\n", quarters, cashFormat(cents));

    // If there are any remaining cents, keep them.
    if (cents > 0)
    {
        printf("\n"
                "Machine error! Thank you for letting me keep $%.2f!\n", cashFormat(cents));
    }

    // End program.
    return 0;
}