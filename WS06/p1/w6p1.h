/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

// ----------------------------------------------------------------------------
// macros
#define MAX_PRODUCTS 3 // Maximum number of products to analyze.
#define SUGGESTED_SERVING 64 // Suggested serving size in grams (g).


// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;       // The product SKU number. (unique whole number)
    double price;  // The product's price.
    int calories;  // Calories per suggested serving. (whole number)
    double weight; // Product weight in pounds.
};


// ----------------------------------------------------------------------------
// function prototypes
// NOTE: parameters are declared const at time of function definition and are not needed,
//       but they are included here to make the use more obvious to the developer.


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int *pos_int_var);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double *pos_double_var);

// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int num_products);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo (const int sequence_num);

// 5. Display the formatted table header
void displayCatFoodHeader (void);

// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku, const double *price, const int calories, const double *weight);

// 7. Logic entry point
void start (void);
