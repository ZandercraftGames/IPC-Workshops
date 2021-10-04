/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3     // Maximum days to collect data from user.

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
    int startYear;        // The starting year of the log
    int startMonth;       // The starting month of the log
    char *monthName;      // The name of the month that the log starts on.
    double morningTotal = 0;  // The total of morning ratings
    double eveningTotal = 0;  // The total of evening ratings
    double overallTotal;      // The overall total of ratings.
    double morningAverage; // The average morning rating
    double eveningAverage; // The average evening rating
    double overallAverage; // The overall average of all ratings

    // Application Introduction
    printf("General Well-being Log\n"
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
        // Continue loop unless conditions have been met.
    }

    // Match month number to month name.
    switch (startMonth) {
        case 1:
            monthName = "JAN";
            break;
        case 2:
            monthName = "FEB";
            break;
        case 3:
            monthName = "MAR";
            break;
        case 4:
            monthName = "APR";
            break;
        case 5:
            monthName = "MAY";
            break;
        case 6:
            monthName = "JUN";
            break;
        case 7:
            monthName = "JUL";
            break;
        case 8:
            monthName = "AUG";
            break;
        case 9:
            monthName = "SEP";
            break;
        case 10:
            monthName = "OCT";
            break;
        case 11:
            monthName = "NOV";
            break;
        case 12:
            monthName = "DEC";
            break;
        default:
            printf("ERROR: An error was encountered when assigning a month name. Please report this to the developer!");
            return 1;
    }

    // Send confirmation to user.
    printf("\n"
           "*** Log date set! ***\n");

    int currentDay;  // Define for backwards compatibility with previous versions of C.

    // Create a loop to prompt the user for the specific number of days.
    for (currentDay = 1; currentDay <= LOG_DAYS; currentDay++) {
        printf("\n%d-%s-%02d\n", startYear, monthName, currentDay);

        int morningCorrect = 0;  // Validation status
        int eveningCorrect = 0;  // Validation status

        double currentMorning;    // Temporary value for the current morning
        double currentEvening;    // Temporary value for the current evening

        while (!morningCorrect) {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &currentMorning);

            if ((currentMorning >= 0) && currentMorning <= 5.0) {
                morningCorrect = 1;
            } else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }

        while (!eveningCorrect) {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &currentEvening);

            if ((currentEvening >= 0) && currentEvening <= 5.0) {
                eveningCorrect = 1;
            } else {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }

        // Calculations
        morningTotal += currentMorning;  // Add the current morning value to the total
        eveningTotal += currentEvening;  // Add the current evening value to the total
    }

    // Final Calculations
    overallTotal = morningTotal + eveningTotal;
    morningAverage = morningTotal / LOG_DAYS;
    eveningAverage = eveningTotal / LOG_DAYS;
    overallAverage = (overallTotal / 2) / LOG_DAYS;

    // Return information to the user.
    printf("\n"
           "Summary\n"
           "=======\n"
           "Morning total rating: %.3lf\n"
           "Evening total rating: %.3lf\n"
           "----------------------------\n"
           "Overall total rating: %.3lf\n"
           "\n"
           "Average morning rating:  %.1lf\n"
           "Average evening rating:  %.1lf\n"
           "----------------------------\n"
           "Average overall rating:  %.1lf\n", morningTotal, eveningTotal, overallTotal,
           morningAverage, eveningAverage, overallAverage);

    return 0;
}