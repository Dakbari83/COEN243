#include<iostream>
using  namespace std;
int main(){
double a,b,c,d,e;
cin>>a>>b>>c>>d;
e = (b*c*d)/5000;
#include <iostream>

using namespace std;

    

    // Multiply by 100 to shift decimal places, add 0.5 for rounding, and truncate extra decimals
    int roundedValue = (e * 100) + 0.5;

    // Separate integer and fractional parts
    int integerPart = roundedValue / 100;
    int fractionalPart = roundedValue % 100;

    // Display the number rounded to 2 decimal places
    cout << "Rounded number with 2 decimal places: " << integerPart << ".";

    // Ensure fractional part has two digits
    if (fractionalPart < 10) {
        cout << "0";  // Add a leading zero if necessary
    }

    cout << fractionalPart << endl;

    return 0;
}

    