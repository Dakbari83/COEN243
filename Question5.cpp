#include<iostream>
using namespace std;
int main(){
    double a,r;
    int b,roundedValue,integerPart,fractionalPart;
    cout<<"Enter the value you want to convert: ";
    cin>>a;
    cout<<"Select the conversion:\n1.\tKilometers to Miles\n2.\tPounds to Kilograms\n3.\tCelsius to Farenheit\n4.\tLiters to Gallons\nEnter your choice (1-4): ";
    cin>>b;
    switch(b){
        case 1:{
        r=a*0.621371;
        //multiple by 100 to shift decimal places, add 0.5 for rounding
        roundedValue = (r*100)+0.5;
        //separate integer and fractional parts
        int integerPart = roundedValue / 100;
        int fractionalPart = roundedValue % 100;

        cout<<a<<" kilometers is equal to "<<integerPart<<".";
        //ensure fractional part has 2 digits
        if (fractionalPart < 10) 
        cout << "0";  // Add a leading zero if necessary
        cout<<fractionalPart<<" miles."<<endl;
        break;}
        case 2:{
            r=a*0.453592;
        roundedValue = (r*100)+0.5;

        int integerPart = roundedValue / 100;
        int fractionalPart = roundedValue % 100;
        

        cout<<a<<" pounds is equal to "<<integerPart<<".";
        if (fractionalPart < 10) 
        cout << "0";  // Add a leading zero if necessary
        cout<<fractionalPart<<" gallons."<<endl;
        break;}
        case 3:{
        r=a*1.8+32;
        roundedValue = (r*100)+0.5;

        int integerPart = roundedValue / 100;
        int fractionalPart = roundedValue % 100;
        cout<<a<<" celsius is equal to "<<integerPart<<".";
        if (fractionalPart<10)
        cout<<"0";

        cout<<fractionalPart<<" farenheit."<<endl;
        break;}
        case 4:{
        r=a*0.264172;
        roundedValue = (r*100)+0.5;

        int integerPart = roundedValue / 100;
        int fractionalPart = roundedValue % 100;
        cout<<a<<" liters is equal to "<<integerPart<<".";
        if (fractionalPart<10)
        cout<<"0";
        cout<<fractionalPart<<" gallons."<<endl;

        break;}
        default:
        cout<<"Invalid selection. Please choose a valid option (1-4)."<<endl;

    }
    return 0;
}
