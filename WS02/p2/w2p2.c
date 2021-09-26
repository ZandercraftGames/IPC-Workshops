/*
	==================================================
	Workshop #2 (Part-2):
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

double cashFormat (int cents)
{
    // Convert the number back into a dollar value by dividing by 100.
    double formatted = ((double) cents / 100);  // Coincidentally the same as in W2P2 instructions.

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
    double serviceFeePercent = 0.05;

    // Prompt user for information.
    printf("Change Maker Machine\n"
           "====================\n"
           "Enter dollars and cents amount to convert to coins: $");
    // Get user's input.
    scanf("%lf", &userInput);

    // Convert the input to cents
    int cents = userInput * 100;

    // Calculate the service fee using the percent value.
    double serviceFee = (cents * serviceFeePercent) + 0.5; // Add 0.5 for rounding.
    cents -= (serviceFee - 1); // subtract the service fee from the total cents owed (accounting for rounding).

    printf("Service fee (%.1lf percent): %.2lf\n", (serviceFeePercent * 100), (cashFormat(serviceFee)));
    printf("Balance to dispense: $%.2lf\n", cashFormat(cents));

    printf("\n");

    int toonies = cents / 200; // Calculate number of toonies.
    cents %= 200; // Remove toonies from cents.
    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, cashFormat(cents));

    int loonies = cents / 100; // Calculate number of loonies.
    cents %= 100; // Remove loonies from remaining cents.
    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, cashFormat(cents));

    int quarters = cents / 25; // Calculate number of quarters.
    cents %= 25; // Remove quarters from remaining cents.
    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, cashFormat(cents));

    int dimes = cents / 10; // Calculate number of dimes.
    cents %= 10; // Remove dimes from remaining cents.
    printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, cashFormat(cents));

    int nickels = cents / 5; // Calculate number of nickels.
    cents %= 5; // Remove nickels from remaining cents.
    printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickels, cashFormat(cents));

    int pennies = cents / 1; // Calculate number of pennies.
    cents %= 1; // Remove pennies from remaining cents.
    printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies, cashFormat(cents));


    // If there are any remaining cents, keep them.
    if (cents > 0)
    {
        printf("\n"
               "Machine error! Thank you for letting me keep $%.2lf!\n", cashFormat(cents));
    } else {
        printf("\n"
               "All coins dispensed!");
    }

    // End program.
    return 0;
}