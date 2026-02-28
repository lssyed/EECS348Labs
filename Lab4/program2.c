// Program 2
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_farenheit(float c) { return (9.0/5.0) * c + 32.0; }

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float f) {return (5.0/9.0) * (f - 32.0); }

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float c) { return c + 273.15; }

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float k) { return k - 273.15; }

// Function to categorize temperature in Celsius
void categorize_temperature(float c) {
    // Categorize the temperature and provide an advisory
    // Freezing: < 0°C
    if (c < 0) printf("Category: Freezing\nAdvisory: Wear a heavy coat and stay warm! \n");
    // Cold: 0°C to 10°C
    else if (c < 10) printf("Category: Cold\nAdvisory: Wear a light jacket! \n");
    // Comfortable: 10°C to 25°C
    else if (c < 25) printf("Category: Comfortable\nAdvisory: Enjoy the beautiful weather! \n");
    // Hot: 25°C to 35°C
    else if (c <= 35) printf("Category: Hot\nAdvisory: Drink plenty of water and stay cool! \n");
    // Extreme Heat: > 35°C
    else printf("Category: Extreme Heat\nAdvisory: Stay indoors and avoid strenuous activities! \n");
}

int main() {
    // Declare variables for temperature input and results
    float temp, c_temp, result;
    // Declare variables for scale selection
    int from_scale, to_scale;
    // Flag to check for valid input
    int valid_input = 0;

    //
    while(valid_input == 0) {
        // Prompt user for temperature value
        printf("\nEnter the temperature value: ");

        // Read temperature input and check for validity
        if (scanf("%f", &temp) != 1) {
            // Handle invalid input
            printf("Error: That isn't a valid number. Please try again. \n");

            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        //  Prompt user for current scale
        printf("Choose current scale (1=Fahrenheit, 2=Celsius, 3=Kelvin): ");

        if (scanf("%d", &from_scale) != 1 || from_scale < 1 || from_scale > 3) {
            // Handle invalid input
            printf("Error: Invalid choice. Please enter 1, 2, or 3. \n");

            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        // Prompt user for target scale
        if (from_scale == 3 && temp < 0.0) {
            // Handle invalid Kelvin input
            printf("Error: Kelvin values can't be negative. Please try again. \n");
            continue;
        }

        // Prompt user for target scale
        printf("Choose target scale (1=Fahrenheit, 2=Celsius, 3=Kelvin):");

        // Read target scale input and check for validity
        if (scanf("%d", &to_scale) != 1 || to_scale < 1 || to_scale > 3) {
            // Handle invalid input
            printf("Error: Invalid choice. Please enter 1, 2, or 3. \n");

            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        //  Check if the user is trying to convert to the same scale
        if (from_scale == to_scale) {
            // Handle same scale conversion
            printf("Error: Can't convert to the same scale. Please try again. \n");
            continue;
        }

        // Stops the loop if all inputs are valid
        valid_input = 1;
    }

    // Convert input temperature to Celsius
    if (from_scale == 1) c_temp = fahrenheit_to_celsius(temp);
    // If the input is already in Celsius, just use it directly
    else if (from_scale == 2) c_temp = temp;
    // If the input is in Kelvin, convert it to Celsius
    else if (from_scale == 3) c_temp = kelvin_to_celsius(temp);

    // Convert from Celsius to the target scale
    if (to_scale == 1) {
        // Convert from Celsius to Fahrenheit
        result = celsius_to_farenheit(c_temp);
        printf("\nResult: %.2f Fahrenheit\n", result);
    // If the target scale is Celsius, we can just use same value
    } else if (to_scale == 2) {
        result = c_temp;
        printf("\nResult: %.2f Celsius\n", result);
    // If the target scale is Kelvin, convert from Celsius to Kelvin
    } else if (to_scale == 3) {
        // Convert from Celsius to Kelvin
        result = celsius_to_kelvin(c_temp);
        printf("\nResult: %.2f Kelvin\n", result);
    }

    // Pass the base Celsius temperature to determine the advisory
    categorize_temperature(c_temp);

    return 0;
}