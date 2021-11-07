/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h> // Standard IO

// User-Defined Libraries
#include "w6p2.h"  // Program Lib w/ fcn prototypes

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int *pos_int_var)
{
    int correct = 0;
    int input;

    // Begin validation loop
    while (!correct) {
        // Get the user's input
        scanf("%d", &input);

        if (input <= 0) {
            // Value is negative or zero. Return error and re-prompt
            printf("ERROR: Enter a positive value: ");
            correct = 0;
        } else {
            correct = 1;
        }
    }

    if (pos_int_var != NULL) {
        // If the pointer value provided is not null, set the variable to value.
        *pos_int_var = input;  // Change variable to the input value.
    }
    return input;   // Return the input value.

}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double *pos_double_var)
{
    int correct = 0;
    double input;

    // Begin validation loop
    while (!correct) {
        // Get the user's input
        scanf("%lf", &input);

        if (input <= 0) {
            // Value is negative or zero. Return error and re-prompt
            printf("ERROR: Enter a positive value: ");
            correct = 0;
        } else {
            correct = 1;
        }
    }

    if (pos_double_var != NULL) {
        // If the pointer value provided is not null, set the variable to value.
        *pos_double_var = input;  // Change variable to the input value.
    }
    return input;   // Return the input value.
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int num_products)
{
    // Print opening message header.
    printf("Cat Food Cost Analysis\n"
           "======================\n\n");

    // Print opening message details.
    printf("Enter the details for %d dry food bags of product data for analysis.\n"
           "NOTE: A 'serving' is %dg\n", num_products, SUGGESTED_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo (const int sequence_num)
{
    struct CatFoodInfo product;

    // Display the sequence's header
    printf("\n"
           "Cat Food Product #%d\n"
           "--------------------\n", (sequence_num + 1));

    // Prompt user for SKU
    printf("SKU           : ");
    getIntPositive(&product.sku);

    // Prompt user for PRICE
    printf("PRICE         : $");
    getDoublePositive(&product.price);

    // Prompt user for WEIGHT
    printf("WEIGHT (LBS)  : ");
    product.weight = getDoublePositive(NULL);

    // Prompt user for CALORIES/SERV
    printf("CALORIES/SERV.: ");
    product.calories = getIntPositive(NULL);

    // All data has been gathered. Return the product.
    return product;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku, const double *price, const int calories, const double *weight)
{
    // Print the cat food's data.
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg (const double *pounds, double *resultKg)
{
    double result;

    // Calculate the amount of kilograms.
    result = *pounds / LBS_TO_KG_FACTOR;

    if (resultKg != NULL) {
        // If the pointer value provided is not null, set the variable to value.
        *resultKg = result;  // Change variable to the input value.
    }
    return result;   // Return the input value.
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG (const double *pounds, int *resultG)
{
    double result;

    // Calculate the amount of grams.
    result = convertLbsKg(pounds, &result) * 1000;

    if (resultG != NULL) {
        // If the pointer value provided is not null, set the variable to the calculated value.
        *resultG = (int) result;  // Change variable to the calculated value.
    }
    return (int) result;   // Return the calculated value.
}

// 10. convert lbs: kg and g
void convertLbs (const double *pounds, double *resultKg, int *resultG)
{

}

// 11. calculate: servings based on gPerServ
double calculateServings (const int gPerServ, const int productGrams, double *resultServings)
{

}

// 12. calculate: cost per serving
double calculateCostPerServing (const double *price, const double *servings, double *resultCostPerServ)
{

}

// 13. calculate: cost per calorie
double calculateCostPerCal (const double *price, const double *calories, double *resultCostPerCal)
{

}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData (const struct CatFoodInfo item)
{

}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", ???);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData (const struct ReportData data, const int isCheapestOption)
{

}

// 17. Display the findings (cheapest)
void displayFinalAnalysis (const struct CatFoodInfo cheapestProductData)
{

}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    // Variable Declarations
    struct CatFoodInfo products[MAX_PRODUCTS];

    // Display the opening message.
    openingMessage(MAX_PRODUCTS);

    // Get the values of every product.
    int i; // Declared outside of loop for backwards-compatibility with older versions of C.
    for (i = 0; i < MAX_PRODUCTS; i++) {
        // Get the cat food info for the product and store it in the array.
        products[i] = getCatFoodInfo(i);
    }

    // Print the table header.
    displayCatFoodHeader();

    // Loop through all values and print them to the table.
    int j; // Declared outside of loop for backwards-compatibility with older versions of C.
    for (j = 0; j < MAX_PRODUCTS; j++) {
        // Print the row for the appropriate entry.
        displayCatFoodData(products[j].sku, &products[j].price, products[j].calories, &products[j].weight);
    }
}
