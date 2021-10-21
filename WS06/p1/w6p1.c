/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>  // Standard IO

// User Libraries
#include "w6p1.h"  // Program Lib w/ fcn prototypes


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
    printf("\n"
           "===========================\n"
           "Starting Main Program Logic\n"
           "===========================\n\n"
           "Cat Food Cost Analysis\n"
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
           "--------------------\n", sequence_num);

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
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku, const double *price, const int calories, const double *weight)
{
    // Print the cat food's data.
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start (void)
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