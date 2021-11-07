/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Zander Maitland
	ID     : 112303219
	Email  : zmaitland@myseneca.ca
	Section: NCC
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3            // Maximum number of products to analyze.
#define SUGGESTED_SERVING 64      // Suggested serving size in grams (g).
#define LBS_TO_KG_FACTOR 2.20462  // Conversion factor from US pounds to kilograms.

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int    sku;      // The product SKU number. (unique whole number)
    double price;    // The product's price.
    int    calories; // Calories per suggested serving. (whole number)
    double weight;   // Product weight in pounds.
};

struct ReportData
{
    int    sku;          // The product SKU number. (unique whole number)
    double price;        // The product's price.
    int    calories;     // Calories per suggested serving (whole number)
    double weightLBS;    // Product weight in pounds.
    double weightKG;     // Product weight in kilograms.
    int    weightG;      // Product weight in grams. (whole number)
    double servings;     // Number of total servings.
    double servingCost;  // Cost per serving.
    double caloriesCost; // Cost of calories per serving.
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku, const double *price, const int calories, const double *weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg (const double *pounds, double *resultKg);

// 9. convert lbs: g
int convertLbsG (const double *pounds, int *resultG);

// 10. convert lbs: kg / g
void convertLbs (const double *pounds, double *resultKg, int *resultG);

// 11. calculate: servings based on gPerServ
double calculateServings (const int gPerServ, const int productGrams, double *resultServings);

// 12. calculate: cost per serving
double calculateCostPerServing (const double *price, const double *servings, double *resultCostPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal (const double *price, const double *calories, double *resultCostPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData (const struct CatFoodInfo item);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData (const struct ReportData data, const int isCheapestOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis (const struct CatFoodInfo cheapestProductData);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
