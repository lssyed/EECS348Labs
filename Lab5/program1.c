// Program 1
#include <stdio.h>

int main() {
    // Initialize sales data and month names from Sample Output
    double sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 
                        72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[12] = {"January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"};
    
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");
    // Returns Month Sales in table format
    for (int i = 0; i < 12; i++) {
        printf("%s\t\t$%.2f\n", months[i], sales[i]);
    }

    // Calculating miimum, maximum, and average sales
    double min = sales[0];
    double max = sales[0];
    double sum = 0.0;
    // min_month and max_month starts from January
    char *min_month = months[0];
    char *max_month = months[0];

    // Find the minimum, maximum, and sum of sales
    for (int i = 0; i < 12; i++) {
        sum = sum + sales[i];
        // Update minimum sales and corresponding month
        if (sales[i] < min) {
            min = sales[i];
            min_month = months[i];
        }
        // Update maximum sales and corresponding month
        if (sales[i] > max) {
            max = sales[i];
            max_month = months[i];
        }
    }

    printf("\nSales summary report: \n");
    printf("Minimum sales: $%.2f (%s)\n", min, min_month);
    printf("Maximum sales: $%.2f (%s)\n", max, max_month);
    printf("Average sales: $%.2f\n", sum / 12.0);

    printf("\nSix-Month moving average report:\n");
    // Calculating the six-month average report
    for (int i = 0; i <= 6; i++) {
        // Calculates the sum of sales for the current six-month period
        double moving_sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            moving_sum = moving_sum + sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i+5], moving_sum / 6.0);
    }

    // Sort the sales data in descending order and print the sorted report
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            // Sort in decending order
            if (sales[i] < sales[j]) {
                // temp_sale swaps values to sort them
                double temp_sale = sales[i];
                // Swap sales values
                sales[i] = sales[j];
                sales[j] = temp_sale;

                // temp_month swaps month names to match the sorted sales
                char *temp_month = months[i];
                // Swaps month names
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }

    printf("\nSales report (highest to lowest):\n");
    printf("Month\t\tSales\n");
    // Print the sorted sales report
    for (int i = 0; i < 12; i++) {
        printf("%s\t\t$%.2f\n", months[i], sales[i]);
    }

    return 0;
}