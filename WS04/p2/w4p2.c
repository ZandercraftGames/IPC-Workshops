/*
	==================================================
	Workshop #4 (Part-2):
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
    double totalCost = 0;             // Keeps track of the total cost of all items added together.
    int forecastSelection;            // Keeps track of the forecast type that the user has selected.
    int hasFinance;                   // Keeps track of if any item has finance options.
    int forecastMonths;               // Keep track of the number of months it will take to pay off the items.
    int priorityFilter;               // Keeps track of the priority filter input when selecting to filter by priority.
    double priorityFilterCost = 0;    // Keeps track of the cost of items when run through the priority filter.
    int priorityFilterHasFinance;     // Keep track of if the priority filter has finance options.

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
        correct = 0; // Reset validity tracker for use in next loop iteration
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
                totalCost += itemCost[i - 1];  // Add cost to total cost.
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
    printf("\n"
           "Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    // Loop through entries in the arrays.
    int j;  // Declare before loop for compatibility
    for (j = 1; j <= itemCount; j++) {
        printf("%3d  %5d    %5c    %11.2lf\n", j, itemPriority[j - 1], itemFinance[j - 1], itemCost[j - 1]);
        if (itemFinance[j - 1] == 'y') {
            hasFinance = 1;
        }
    }

    // Print summary to user
    printf("---- -------- -------- -----------\n"
           "                      $%11.2lf\n", totalCost);

    // Start input validation loop for forecast menu
    while (!correct) {
        // Prompt user for input
        printf("\n"
               "How do you want to forecast your wish list?\n"
               " 1. All items (no filter)\n"
               " 2. By priority\n"
               " 0. Quit/Exit\n"
               "Selection: ");
        scanf("%d", &forecastSelection);

        // Validate user's input
        if (forecastSelection == 1) {
            // User wants all values.
            correct = 0;

            printf("\n====================================================\n");

            // Calculations
            forecastMonths = ((int) ((totalCost * 100) + 0.5) / (int) ((userIncome * 100) + 0.5)) + 1;  // Calculate based on income and cost in cents. 0.5 added to prevent rounding errors and 1 for the end of the month.

            // Output details
            printf("Filter:   All items\n"
                   "Amount:   $%.2lf\n"
                   "Forecast: %d years, %d months\n", totalCost, forecastMonths / 12, forecastMonths % 12);

            if (hasFinance) {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");

        } else if (forecastSelection == 2) {
            // User wants to filter by priority.
            correct = 0;

            // Begin nested validation loop
            while (!correct) {
                // Prompt user to provide priority to filter by.
                printf("\n"
                       "What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFilter);

                // Validate response
                if ((priorityFilter >= 1) && (priorityFilter <= 3)) {
                    correct = 1;
                } else {
                    // Wrong input. Return error.
                    printf("ERROR: Value must be between 1 and 3\n");
                    correct = 0;
                }
            }

            // Iterate through all entries searching for those with the right priority
            int k;  // Defined outside of loop for backwards compatibility with previous versions of C.
            for (k = 1; k <= MAX_ITEMS; k++)
            {
                if (itemPriority[k - 1] == priorityFilter) {
                    priorityFilterCost += itemCost[k - 1];  // Add to the filtered cost.
                    if (itemFinance[k - 1] == 'y') {
                        priorityFilterHasFinance = 1;
                    }
                }
            }

            correct = 0;  // Reset for next loop iteration

            // Calculations
            forecastMonths = ((int) ((priorityFilterCost * 100) + 0.5) / (int) ((userIncome * 100) + 0.5)) + 1;  // Calculate based on income and cost in cents. 0.5 added to prevent rounding errors and add one since it represents the whole month.

            printf("\n====================================================\n");

            printf("Filter:   by priority (%d)\n"
                   "Amount:   $%.2lf\n"
                   "Forecast: %d years, %d months\n", priorityFilter, priorityFilterCost, forecastMonths / 12, forecastMonths % 12);

            if (priorityFilterHasFinance) {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        } else if (forecastSelection == 0) {
            // Ends loop and exits the program.
            correct = 1;
        } else {
            // The user input an invalid value. Return error.
            printf("\n"
                   "ERROR: Invalid menu selection.\n");
            correct = 0;
        }
        priorityFilterCost = 0;  // Reset cost so the program doesn't double it on th next run.
        priorityFilterHasFinance = 0; // Reset status for next run.
    }

    correct = 0; // Reset validity tracker for use in next loop.

    // Print exit message
    printf("\n"
           "Best of luck in all your future endeavours!\n");

    return 0; // End program
}