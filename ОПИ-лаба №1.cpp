#include <iostream>
#include <iomanip>

using namespace std;

const int MATRIX_SIZE = 17;

void generateRandomMatrix(int**&);
void printMatrix(int**&);
void numberOfSmallerElements(int**&);
void numberOfNonZeroRows(int**&);
void selectedElements(int**&);

int main()
{
    int** matrix = nullptr;

    generateRandomMatrix(matrix);
    printMatrix(matrix);
    numberOfSmallerElements(matrix);
    numberOfNonZeroRows(matrix);
    selectedElements(matrix);

    return 0;
}

void generateRandomMatrix(int**& matrix) {
    const int MIN_ELEMENT = -12;
    const int MAX_ELEMENT = 12;
    matrix = new int* [MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i] = new int[MATRIX_SIZE];
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
        }
    }
}

void printMatrix(int**& matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << setw(3) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void numberOfSmallerElements(int**& matrix) {
    int value = 0, countOfNumbers = 0;
    cout << "Enter your value: " << endl;
    cin >> value;
    cout << "\n";
    for (int i = 0; i < MATRIX_SIZE; i++) {
        cout << "The line " << i + 1 << " contains the number of elements less than the entered value: ";
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] < value) {
                countOfNumbers += 1;
            }
        }
        cout << countOfNumbers << endl;
        countOfNumbers = 0;
    }
}

void numberOfNonZeroRows(int**& matrix) {
    int numberOfNonZeroRows = 0, numberOfZeroElements = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] == 0) {
                numberOfZeroElements++;
            }
        }
        if (numberOfZeroElements != MATRIX_SIZE) {
            numberOfNonZeroRows++;
        }
        numberOfZeroElements = 0;
    }
    cout << "Number of non-zero rows: " << numberOfNonZeroRows << endl; //здесь был вася
}

void selectedElements(int**& matrix) {
    int sum = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "The sum of the selected elements = " << sum << endl;
}
