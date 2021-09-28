/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/
#define _CRT_SECURE_NO_WARNINGS

// Imports
#include <stdio.h>  // Standard IO

// Macro Definitions
#define MIN_YEAR 2010  // Minimum year that can be entered.
#define MAX_YEAR 2021  // Maximum year that can be entered.

// Main Function
int main(void)
{
    /*
     * Steps:
     * 1. Display title for application
     * 2. Prompt the user for year and month for the log.
     * 3. Assign the provided values to two integer variables.
     * 4. Validate the entered values to ensure that they are correct.
     *      - First value must be in the range of years
     *      - Second value must be in range of months
     * 5. If the tests fail, display error message and prompt again.
     * 6. When set, output success prompt.
     * 7. Display start date in YYYY-MMM-DD format. Starts on DD = 01
     *      - YYYY: year
     *      - MMM - 3 chars of the month's name
     *      - DD: day # (has to be 2 digits)
     */

    // Main Variables
    const int JAN = 1;  // Assign constants for January and December's mo. nums.
    const int DEC = 12;
    int correctYear = 0;  // Used to track if the user has input the correct year value.
    int correctMonth = 0; // Used to track if the user has input the correct month value.
    int startYear;      // The starting year of the log
    int startMonth;     // The starting month of the log

    // Application Introduction
    printf("General Well-bring Log\n"
           "======================\n");

    // Start user prompt loop.
    while (!correctMonth || !correctYear) {
        // Reset values
        correctYear = 0;
        correctMonth = 0;

        // Prompt user for start date of log.
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &startYear, &startMonth);

        // Check if the year is within the correct range.
        if ((startYear >= MIN_YEAR) && (startYear <= MAX_YEAR)) {
            correctYear = 1;
        } else {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            correctYear = 0;
        }

        // Check if the month is within the correct range.
        if ((startMonth >= JAN) && (startMonth <= DEC)) {
            correctMonth = 1;
        } else {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            correctMonth = 0;
        }
        // Continue loop as the conditions have not been met.
        printf("%d %d", correctYear, correctMonth);
    }

    // Loop has successfully finished. Send confirmation to user.
    printf("*** Log date set! ***\n");



    return 0;
}