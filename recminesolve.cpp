#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
    long long n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0){
        cout << "Please enter a non-negative number.";
        return 0;
    }

    cout << "Numbers from 1 to n: ";
    for(long long i =1; i <=n; i++){
        cout << i << " ";
    }
    cout << endl;
}
