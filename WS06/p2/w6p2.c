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
    result = convertLbsKg(pounds, NULL) * 1000;

    if (resultG != NULL) {
        // If the pointer value provided is not null, set the variable to the calculated value.
        *resultG = (int) result;  // Change variable to the calculated value.
    }
    return (int) result;   // Return the calculated value.
}

// 10. convert lbs: kg and g
void convertLbs (const double *pounds, double *resultKg, int *resultG)
{
    *resultKg = convertLbsKg(pounds, NULL);  // Change resultKG to value.
    *resultG = convertLbsG(pounds, NULL);  // Change resultG to value.
}

// 11. calculate: servings based on gPerServ
double calculateServings (const int gPerServ, const int productGrams, double *resultServings)
{
    double result;
    result = (double) productGrams / (double) gPerServ;

    if (resultServings != NULL) {
        // If the pointer value provided is not null, set the variable to the calculated value.
        *resultServings = result;  // Change variable to the calculated value.
    }
    return result;   // Return the calculated value.
}

// 12. calculate: cost per serving
double calculateCostPerServing (const double *price, const double *servings, double *resultCostPerServ)
{
    double result;

    // Calculate the cost per serving.
    result = *price / *servings;

    if (resultCostPerServ != NULL) {
        // If the pointer value provided is not null, set the variable to the calculated value.
        *resultCostPerServ = result;  // Change variable to the calculated value.
    }
    return result;   // Return the calculated value.
}

// 13. calculate: cost per calorie
double calculateCostPerCal (const double *price, const double *calories, double *resultCostPerCal)
{
    double result;

    // Calculate the cost per calorie.
    result = *price / *calories;

    if (resultCostPerCal != NULL) {
        // If the pointer value provided is not null, set the variable to the calculated value.
        *resultCostPerCal = result;  // Change variable to the calculated value.
    }
    return result;   // Return the calculated value.
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData (const struct CatFoodInfo item)
{
    struct ReportData data;  // Local instance of data for modification

    // Copy over data from the Cat Food item
    data.sku = item.sku;            // Unique item identifier
    data.price = item.price;        // Price
    data.calories = item.calories;  // Calories per suggested serving
    data.weightLBS = item.weight;   // Weight in pounds

    // Calculate weight attributes
    convertLbs(&data.weightLBS, &data.weightKG, &data.weightG);

    // Calculate servings
    calculateServings(SUGGESTED_SERVING, data.weightG, &data.servings);

    // Calculate costs
    double calories = data.calories * data.servings;  // Calculate the total calories in the product
    calculateCostPerCal(&data.price, &calories, &data.caloriesCost);  // Calculate cost per calorie
    calculateCostPerServing(&data.price, &data.servings, &data.servingCost);  // Calculate the cost per serving

    return data; // Return the data structure.
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SUGGESTED_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData (const struct ReportData data, const int isCheapestOption)
{
    // Print the data to the screen.
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf%3s\n", data.sku, data.price, data.weightLBS,
    data.weightKG, data.weightG, data.calories, data.servings, data.servingCost, data.caloriesCost,
    isCheapestOption ? " ***" : "");  // NOTE: Appends "***" to the end if the item is the cheapest option.
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis (const struct CatFoodInfo cheapestProductData)
{
    // Print Header
    printf("Final Analysis\n"
           "--------------\n"
           "Based on the comparison data, the PURRR-fect economical option is:\n");

    // Print the data of the best product
    printf("SKU:%d Price: $%.2lf\n", cheapestProductData.sku, cheapestProductData.price);

    // Display closing message
    printf("Happy Shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    // Variable Declarations
    struct CatFoodInfo products[MAX_PRODUCTS];
    struct ReportData reportProducts[MAX_PRODUCTS];
    double cheapestItemCost = -1;  // Used for tracking the cheapest item on the basis of cost
    int cheapestItemIndex;    // The index of the cheapest item found

    // Display the opening message.
    openingMessage(MAX_PRODUCTS);

    // Get the values of every product.
    int i; // Declared outside of loop for backwards-compatibility with older versions of C.
    for (i = 0; i < MAX_PRODUCTS; i++) {
        // Get the cat food info for the product and store it in the array.
        products[i] = getCatFoodInfo(i);

        // Calculate the report data based on information provided.
        reportProducts[i] = calculateReportData(products[i]);

        // Check if the item is the cheapest item yet. (checks if cheaper or if cheapestItem has not been initialized yet)
        if ((reportProducts[i].servingCost <= cheapestItemCost) || cheapestItemCost == -1) {
            cheapestItemCost = reportProducts[i].servingCost;
            cheapestItemIndex = i;
        }
    }

    // Print the table header.
    displayCatFoodHeader();

    // Loop through all values and print them to the table.
    int j; // Declared outside of loop for backwards-compatibility with older versions of C.
    for (j = 0; j < MAX_PRODUCTS; j++) {
        // Print the row for the appropriate entry.
        displayCatFoodData(products[j].sku, &products[j].price, products[j].calories, &products[j].weight);
    }

    printf("\n"); //newline

    // ================
    // Analysis Report
    // ================

    // Display header
    displayReportHeader();

    // Display table values
    int k;
    for (k = 0; k < MAX_PRODUCTS; k++) {
        if (k == cheapestItemIndex) {
            displayReportData(reportProducts[k], 1);
        } else {
            displayReportData(reportProducts[k], 0);
        }
    }

    printf("\n"); // newline

    // Display final analysis
    displayFinalAnalysis(products[cheapestItemIndex]);

}
