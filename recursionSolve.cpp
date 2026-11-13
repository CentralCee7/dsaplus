#include <iostream>   // Allows us to use cin and cout.
#include <string>     // Allows us to use string.
#include <vector>     // Allows us to use vector (a dynamic list).

using namespace std;  // Lets us write cout instead of std::cout.

int main() {

    // 1. Print numbers from 1 to n.
    // 2. Calculate the sum from 1 to n.
    // 3. Calculate the factorial of n.

    long long n;  // Declares a variable to store n.

    cout << "Enter n: ";  // Asks the user to enter n.
    cin >> n;             // Takes n as input.

    if (n < 0) {  // Checks whether n is negative.
        cout << "Please enter a non-negative number.";
        return 0;  // Stops the program.
    }

    cout << "Numbers from 1 to n: ";

    for (long long i = 1; i <= n; i++) {
        cout << i << " ";  // Prints each number.
    }

    cout << endl;  // Moves the cursor to the next line.

    // Calculate the sum of numbers from 1 to n.

    long long sum = 0;  // Initializes sum with 0.

    for (long long i = 1; i <= n; i++) {
        sum = sum + i;  // Adds i to sum.
    }

    cout << "Sum = " << sum << endl;

    // Calculate the factorial of n.

    if (n <= 20) {  // Checks whether factorial fits in long long.
        long long factorial = 1;  // Initializes factorial with 1.

        for (long long i = 1; i <= n; i++) {
            factorial = factorial * i;  // Multiplies factorial by i.
        }

        cout << "Factorial = " << factorial << endl;
    }
    else {
        cout << "Factorial is too large for long long." << endl;
    }

    // 4. Calculate the sum of digits.
    // 5. Count the number of digits.

    string number;  // Stores the number as a string.

    cout << "\nEnter a number for digit operations: ";
    cin >> number;

    long long digitSum = 0;  // Stores the sum of digits.
    int digitCount = 0;     // Stores the number of digits.

    for (char digit : number) {

        if (digit >= '0' && digit <= '9') {

            digitSum = digitSum + (digit - '0');
            digitCount++;
        }
    }

    cout << "Sum of digits = " << digitSum << endl;
    cout << "Number of digits = " << digitCount << endl;

    // 6. Calculate the nth term of a Fibonacci series.

    int position;

    cout << "\nEnter Fibonacci position (0 to 92): ";
    cin >> position;

    if (position < 0 || position > 92) {
        cout << "Please enter a position between 0 and 92." << endl;
    }
    else {
        long long first = 0;
        long long second = 1;

        for (int i = 2; i <= position; i++) {

            long long next = first + second;

            first = second;
            second = next;
        }

        if (position == 0) {
            cout << "Fibonacci term = 0" << endl;
        }
        else {
            cout << "Fibonacci term = " << second << endl;
        }
    }

    // 7. Calculate a to the power b.

    long long a, b;

    cout << "\nEnter base a: ";
    cin >> a;

    cout << "Enter exponent b: ";
    cin >> b;

    if (b < 0) {
        cout << "Please enter a non-negative exponent." << endl;
    }
    else {
        long long result = 1;

        for (long long i = 1; i <= b; i++) {
            result = result * a;
        }

        cout << "Result = " << result << endl;
    }

    // 8. Print the list elements.
    // 9. Find the largest element.
    // 10. Find the smallest element.

    int size;

    cout << "\nEnter the size of the list: ";
    cin >> size;

    if (size <= 0) {
        cout << "List size must be positive." << endl;
        return 0;
    }

    vector<long long> numbers(size);  // Creates a list.

    cout << "Enter " << size << " elements: ";

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];  // Takes list elements as input.
    }

    // Print all list elements.

    cout << "List elements: ";

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // Find the largest and smallest elements.

    long long largest = numbers[0];
    long long smallest = numbers[0];

    for (int i = 1; i < size; i++) {

        if (numbers[i] > largest) {
            largest = numbers[i];
        }

        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    cout << "Largest element = " << largest << endl;
    cout << "Smallest element = " << smallest << endl;

    return 0;  // Successfully ends the program.
}

 