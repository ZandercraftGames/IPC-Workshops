/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

// Macros and Library Imports
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10
#include <stdio.h>

// Main Function
int main(void) {
    // Variable Declarations
    const double min_income = 500;    // The minimum income that the program will accept.
    const double max_income = 400000; // The maximum income that the program will accept.
    int correct = 0;                  // Used for keeping track of if user input is correct.
    double userIncome;                // The monthly net income that the user provides.
    int itemCount;                    // The number of wish list items that the user provides.
    const double min_cost = 100;      // The minimum cost of an item.

    // Parallel Array Declaration
    double itemCost[MAX_ITEMS];       // The array used to store the cost of the items.
    int itemPriority[MAX_ITEMS];      // The array used to store the priority of the items.
    char itemFinance[MAX_ITEMS];    // The array used to store the finance options of the items.

    // Print program introduction
    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n");

    // Start input validation loop for monthly net income.
    while (!correct) {
        // Prompt user for their monthly net income.
        printf("\n"
               "Enter your monthly NET income: $");
        scanf("%lf", &userIncome);

        // Validate answer to be within the range.
        if ((userIncome >= min_income) && (userIncome <= max_income)) {
            correct = 1;
        } else if (userIncome < min_income) {
            // The value provided is too small. Respond with an error.
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", min_income);
            correct = 0;
        } else {
            // The value provided is too large. Respond with an error.
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", max_income);
            correct = 0;
        }
    }

    correct = 0; // Reset validity tracker for use in next loop.

    // Start input validation loop for item count.
    while (!correct) {
        // Prompt user for the item count.
        printf("\n"
               "How many wish list items do you want to forecast?: ");
        scanf("%d", &itemCount);

        // Validate the answer to be within the range.
        if ((itemCount <= MAX_ITEMS) && itemCount >= 1) {
            correct = 1;
        } else {
            // Invalid answer. return an error.
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
            correct = 0;
        }
    }

    correct = 0; // Reset validity tracker for use in next loop.

    int i; // Initialize the variable before the loop for backwards compatibility with older C versions.
    for (i = 1; i <= itemCount; i++) {
        // Print introduction to item
        printf("\n"
               "Item-%d Details:\n", i);

        // Begin validation loop for cost
        while (!correct) {
            // Prompt the user for the item's cost
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i - 1]);

            // Validate the answer to be within the range.
            if (itemCost[i - 1] >= min_cost) {
                correct = 1;
            } else {
                // The user entered a value under the minimum cost, return error.
                printf("      ERROR: Cost must be at least $%.2lf\n", min_cost);
                correct = 0;
            }
        }

        correct = 0; // Reset validity tracker for use in next loop.

        // Begin validation loop for priority
        while (!correct) {
            // Prompt user for the item's priority
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i - 1]);

            // Validate the answer to be within the range.
            if ((itemPriority[i - 1] >= 1) && (itemPriority[i - 1] <= 3)) {
                correct = 1;
            } else {
                // The answer is invalid. Return an error.
                printf("      ERROR: Value must be between 1 and 3\n");
                correct = 0;
            }
        }

        correct = 0; // Reset validity tracker for use in next loop.

        // Begin validation loop for financing options.
        while (!correct) {
            // Prompt user for financing options
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinance[i - 1]);  // Whitespace avoids automatically taking newline from input stream.

            // Validate the answer
            if (itemFinance[i - 1] == 'y' || itemFinance[i - 1] == 'n') {
                correct = 1;
            } else {
                // Incorrect answer provided. Return error.
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                correct = 0;
            }
        }

        correct = 0; // Reset validity tracker for use in next loop.
    }

    // All values have been collected. Print out the table.
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    // Loop through entries in the arrays.
    int j;  // Declare before loop for compatibility
    for (j = 1; j <= itemCount; j++) {
        printf("%3d  %5d    %5c    %11.2lf\n", j, itemPriority[j - 1], itemFinance[j - 1], itemCost[j - 1]);
    }
}