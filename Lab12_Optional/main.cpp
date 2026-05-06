#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Helper function to check if a single character is a number between 0 and 9
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Takes the chunk of text that looks like a number
// and translates it into an actual math value. 
// Returns true is the chunk is mathematically perfect, false if it breaks a rule. 
bool validateAndCompute(string chunk, double& final_value) {
    int i = 0;
    int length = chunk.length();
    double sign = 1.0;

    // 1. Check if the number starts with a positive/negative sign. 
    if (chunk[i] == '+' || chunk[i] == '-') {
        if (chunk[i] == '-') sign = -1.0;
        i++;
    }

    double base_value = 0.0;
    int digit_count = 0;

    // 2. Read the main integer part before any decimal point
    while (i < length && isDigit(chunk[i])) {
        // Shifts current value left by 1 decimal place, then adds the new digit
        base_value = (base_value * 10.0) + (chunk[i] - '0');

        // Stop if the number is getting too big for a double
        if (base_value >= 1.7e308) return false;

        digit_count++;
        i++;
    }

    // 3. If there is a decimal point, read the fraction part
    if (i < length && chunk[i] == '.') {
        i++;
        // Starts at the 10th place, then 100ths, ...
        double fraction = 0.1;
        while (i < length && isDigit(chunk[i])) {
            base_value = base_value + ((chunk[i] - '0') * fraction);
            fraction = fraction / 10.0;
            digit_count++;
            i++;
        }
    }

    // A standalone decimal with no digits is invalid
    if (digit_count == 0) return false;

    bool has_exponent = false;
    double exp_sign = 1.0;
    int exp_value = 0;
    int exp_digit_count = 0;

    // 4. Check for Scientific Notation
    if (i < length && (chunk[i] == 'e' || chunk[i] == 'E')) {
        has_exponent = true;
        i++;

        // Exponent can also have its own plus/minus sign
        if (i < length && (chunk[i] == '+' || chunk[i] == '-' )) {
            if (chunk[i] == '-') exp_sign = -1.0;
            i++;
        }

        // Read the exponent digits as an integer
        while (i < length && isDigit(chunk[i])) {
            if (exp_value < 10000) {
                exp_value = (exp_value * 10) + (chunk[i] - '0');
            }
            exp_digit_count++;
            i++;
        }

        // If we have an 'e', we MUST have digits after it
        if (exp_digit_count == 0) return false;
    }

    // 5. Check for a bad character
    if (i != length) return false;

    final_value = base_value;

    // 6. Apply exponent math if it exists
    if (has_exponent) {
        if (exp_sign == 1.0) {
            for (int count = 0; count < exp_value; count++) {
                final_value = final_value * 10.0;

                if (final_value >= 1.7e308) return false; // Range protection
            }
        } else {
            // Negative exponent: divide by 10
            for (int count = 0; count < exp_value; count++) {
                final_value = final_value / 10.0;
            }
        }
    }

    // Apply the original positive/negative sign to final answer
    final_value = final_value * sign;
    return true;
}

// Scans left-to-right to seperate garbage from valid numbers
double extractNumeric(const string& str) {
    int length = str.length();
    int valid_numbers_found = 0;
    int invalid_attempts = 0;
    double best_number = -999999.99; // Represents failure

    // Loops through every single character in the string
    for (int i = 0; i < length; i++) {
        char c = str[i];
        bool number_starts_here = false;

        // Looks ahead, to check if it starts as a number
        if (isDigit(c)) {
            number_starts_here = true; // Digits always start numbers
        } else if (c == '+' || c == '-') {
            // Signs only count if a digit or decimal is immediately next to them
            if (i + 1 < length && (isDigit(str[i+1]) || str[i+1] == '.')) {
                number_starts_here = true;
            }
        } else if (c == '.') {
            // Decimals only count if a digit is immediately next to them
            if (i + 1 < length && isDigit(str[i+1])) {
                number_starts_here = true;
            }
        }

        // Extracts the whole sequence
        if (number_starts_here) {
            int j = i;
            bool has_dot = false;
            bool has_e = false;
            string chunk = "";

            // Scoops characters as long as they fit a math problem
            while (j < length) {
                char curr = str[j];
                bool belongs = false;

                if (isDigit(curr)) {
                    belongs = true;
                } else if (curr == '.') {
                    if (!has_dot && !has_e) { // Only one dot is allowed, it shouldn't be inside an exponent
                        belongs = true;
                        has_dot = true;
                    }
                } else if (curr == 'e' || curr == 'E') {
                    if (!has_e) { // Only 1 e is allowed
                        belongs = true;
                        has_e = true;
                    }
                } else if (curr == '+' || curr == '-') {
                    if (j == i) { // Allowed at the beginning of the chunk
                        belongs = true;
                    } else if (str[j-1] == 'e' || str[j-1] == 'E') { // Allowed after an e
                        belongs = true;
                    }
                }

                // If it belongs, add it to the chunk and keep going
                if (belongs) {
                    chunk += curr;
                    j++;
                } else {
                    break; // There is another character that isn't a math character
                }
            }

            // Sees if its mathematically perfect
            double value = 0.0;
            if (validateAndCompute(chunk, value)) {
                valid_numbers_found++;
                best_number = value;
            } else {
                invalid_attempts++; // It was broken
            }

            // Moves forward to main loop
            i = j - 1;
        }
    }

    // Traps: If there were any broken attempts, the string is poisoned.
    // If we found more than one number, its ambiguous. 
    // If there were no numbers, its empty. 
    if (invalid_attempts > 0 || valid_numbers_found > 1 || valid_numbers_found == 0) {
        return -999999.99;
    }

    return best_number; // Success
}

// Handles input loop and formatting
int main() {
    string input;

    // Loops forever until user types 'END'
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        getline(cin, input);

        if (input == "END") {
            cout << "Program terminated.\n";
            break; // Exits the while loop
        }

        // Runs parser
        double result = extractNumeric(input);

        if (result == -999999.99) {
            cout << "Invalid input: no valid floating-point number found\n";
        } else {
            // Force the output to show 4 decimal points
            cout << "Extracted number: " << fixed << setprecision(4) << result << "\n";
        }
    }

    return 0;
}