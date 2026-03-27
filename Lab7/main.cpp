#include <iostream>
#include <fstream>

using namespace std;

// Matrix object
class Matrix{

public: // Everything is public
    // Stores size of matrix
    int size;
    // Creates a 2D array
    int data[20][20];

    // Reads numbers from file
    void readFromFile(ifstream& file) {
        // Loops through each row
        for (int i = 0; i < size; i++) {
            // Loops through each column of that row
            for (int j = 0; j < size; j++) {
                // Reads next number from file and saves it
                file >> data[i][j];
            }
        }
    }

    // Prints the matrix
    void display() {
        // Loops through each row
        for (int i = 0; i < size; i++) {
            // Loops through each column
            for (int j = 0; j < size; j++) {
                // Prints the number
                cout << data[i][j] << "\t";
            }
            // Moves to the next line after finishing a row
            cout << endl;
        }
    }

    // Adds matrices together
    Matrix operator+(Matrix other) {
        // Creates a blank matrix
        Matrix result;
        // Maintains the size of matrix
        result.size = size;
        // Loops through rows
        for (int i = 0; i < size; i++) {
            // Loops through columns
            for (int j = 0; j < size; j++) {
                // Adds them together and saves it
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        // Returns the finished matrix
        return result;
    }

    // Multiplies matrices together
    Matrix operator*(Matrix other) {
        // Creates a blank matrix
        Matrix result;
        // Maintains the size of matrix
        result.size = size;
        // Loops through rows
        for (int i = 0; i < size; i++) {
            // Loops through columns
            for (int j = 0; j < size; j++) {
                // Starts from 0
                result.data[i][j] = 0;
                // Loops to multiply
                for (int k = 0; k < size; k++) {
                    // Multiplies each row and column and adds it the the matrix
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        // Returns the finished matrix
        return result;
    }

    // Calculates the total diagonals
    void sumOfDiagonals() {
        // Starts at 0, eventaully holds the total
        int sum = 0;
        // Loops through the rows
        for (int i = 0; i < size; i++) {
            // Adds top-left diagonal to bottom-right diagonal
            sum += data[i][i];
            // Adds top-right diagonal to bottom-left diagonal
            sum += data[i][size - 1 -i];
        }
        // Prints final total to user
        cout << "Sum of Diagonals: " << sum << endl;
    }

    // Swaps two rows
    void swapRows(int row1, int row2) {
        // Loops through columns of provided rows
        for (int j = 0; j < size; j++) {
            // Saves 1st row's number in a temporary space
            int temp = data[row1][j];
            // Overwrites 1st row's number with 2nd row number
            data[row1][j] = data[row2][j];
            // Saved number is now in the 2nd row
            data[row2][j] = temp;
        }
    }
};

int main() {
    // Opens the file that contains input from user
    ifstream file("matrix.txt");

    // Holds size of matrix
    int n;
    // Reads 1st number from file
    file >> n;

    // Creates 2 Matrix objects
    Matrix mat1, mat2;
    // Sets size of 1st matrix
    mat1.size = n;
    // Sets size of 2nd matrix
    mat2.size = n;

    // Saves the numbers into Matrix 1
    mat1.readFromFile(file);
    // Saves the numbers into Matrix 2
    mat2.readFromFile(file);
    file.close();

    cout << "Matrix 1: " << endl;
    mat1.display();

    cout << "Matrix 2: " << endl;
    mat2.display();

    cout << "\nAddition: " << endl;
    Matrix sum = mat1 + mat2;
    sum.display();

    cout << "\nMultiplication: " << endl;
    Matrix product = mat1 * mat2;
    product.display();

    cout << "\nDiagonals of Matrix 1: " << endl;
    mat1.sumOfDiagonals();

    cout << "\nDiagonals of Matrix 2: " << endl;
    mat2.sumOfDiagonals();

    cout << "\nMatrix 1 after swapping row 0 and 2: " << endl;
    mat1.swapRows(0, 2);
    mat1.display();

    return 0;
}