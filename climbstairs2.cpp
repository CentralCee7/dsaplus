#include <iostream>

using namespace std;

// Recursive function to count the number of plans
int countPlans(int n) {
    // 1. Base Cases [Rubric: 4 marks]
    // If n goes below 0, this path is invalid (she read too many)
    if (n < 0) {
        return 0; 
    }
    // If n is exactly 0, she finished exactly the required chapters (1 valid plan)
    if (n == 0) {
        return 1; 
    }
    
    // 2. Recursive Case [Rubric: 6 marks]
    // She can choose to read 1, 2, or 3 chapters today. 
    // We add the possibilities of all three choices together.
    return countPlans(n - 1) + countPlans(n - 2) + countPlans(n - 3);
}

int main() {
    int n;
    
    // 3. Input taken from the user [Rubric: 2 marks]
    if (cin >> n) {
        // 4. Correct output in the required format [Rubric: 3 marks]
        cout << "Number of ways: " << countPlans(n) << endl;
    }
    
    return 0;
}