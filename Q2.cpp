#include <iostream>
#include<cmath>
#include<iomanip> // For fixed and setprecision
using namespace std;

// Function prototypes
void function1(int, int);
void function2(int, int, double&);
double function3(int, int);
void function4(int, int);
int bionomialCoeff(int, int);
int countDigits(int);

int main(){
    int a,b;
    double result;
    char c;

    // Ask the user to enter the lower and upper bound
    cout<<"Please enter two positive integer numbers: (Lower bound/Upper bound): ";
    cin>>a>>b;

    // Ask the user to choose the function
    cout<<"\nPlease enter a character: ";
    cin>>c;

    // Choose function according to the user's choice
    switch(c){
        case 'a':
            // If user enters choice a, call function 1
            function1(a, b); 
            break;

        case 'b':
            // The function will change the value of result because it's pass by reference
            function2(a, b, result); 
            cout<<"\nThe log10 difference between two numbers is "<<fixed<<setprecision(4)<<result<<endl;
            break;

        case 'c':
            // Set fixed and precision 3: always 3 decimal places
            cout<<"\nThe value of sum is: "<<fixed<<setprecision(3)<<function3(a,b)<<endl; 
            break;

        case 'd':
            cout<<"\nThe triangle pattern: \n"<<endl;
            function4(a, b);
            break;

        default:
            // In case user enters an undefined character
            cout<<"\nInvalid input"<<endl; 
            break;
    }
    return 0;
}

void function1(int a, int b){
    cout<<"\nList of numbers in this interval which are multiple of both 3 and 5: ";

    // Go through all numbers between lower and upper bound, inclusive
    for (int i = a; i <= b; i++){ 

        // Check if the number is both divisible by 3 and 5
        if (((i%3) == 0) && ((i % 5) == 0)){ 
            cout<<i<<" ";
        }
    }
}

void function2(int a,int b, double& result){ //call by reference for result
    result = log10(abs(a-b)); //save result

}

double function3(int a,int b){
    double sum=0;

    // Calculate sum, i goes from lowerbound to upper, and j goes from upperbound to lower
    for(int i = a, j = b; j >= a; i++, j--){ 

        // Make one of the integers temporarily double type for the result to have decimals
        sum += static_cast<double>(j) / i; 
    }
    return sum;
}

// Function to count the number of digits in a number
int countDigits(int num) {
    int digits = 0;
    do {
        num /= 10;
        digits++;
    } while (num != 0);
    return digits;
}

// Recursive function to calculate the binomial coefficient T(n, k)
int binomialCoeff(int n, int k) {
    // Base case: the first and last elements of every row are 1
    if (k == 0 || k == n) 
        return 1;

    // Recursive step: calculate T(n, k) as T(n-1, k-1) + T(n-1, k)
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k); 
}

void function4(int a, int b) {
    // Calculate the sum of the lower and upper bound numbers
    int sum = a + b;

    // Get the last digit of the sum
    int row = sum % 10;

    // If the last digit is 0, don't print anything
    if (row == 0)
        return;
    
    
    for (int i = 0; i < row; i++) {
        // Print leading spaces for alignment
        for (int j = 1; j <= row - i - 1; j++)
            cout<<" ";

        // Print numbers in the row
        for (int k = 0; k <= i; k++) {
            cout << binomialCoeff(i, k) << " ";
        }
        cout << endl; // Move to the next line after each row
    }
}

        