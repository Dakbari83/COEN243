#include<iostream>
using namespace std;
int main(){
    double a,b,c,d,e,f;
    int r;
    
    
    cout<<"Enter the package weight in kilograms: ";
    cin>>a;
    cout<<"Enter the package dimensions (length, width, height) in centimeters: ";
    cin>>b>>c>>d;
    e=(b*c*d)/5000;

    //Multiply by 100 to shift decimal places, add 0.5 for rounding.
    r = (e*100)+0.5;
    //separate integer and fractional parts
    int integer = r/100;
    int fraction = r%100;
    
    cout<<"The dimensional weight is "<<integer<<".";
    //ensure fractional part has 2 digits
    if (fraction<10)
    cout<<"0";
    
    cout<<fraction<<" kg."<<endl;
    if(e>=a)
    f=e;
    else
    f=a;
    if (f<=2)
    cout<<"The shipping cost is $5."<<endl;
    else if (f>2 && f<=10)
    cout<<"The shipping cost is $10."<<endl;
    else if (f>10 && f<=20)
    cout<<"The shipping cost is $20."<<endl;
    else
    cout<<"The package is too heavy to be shipped";
    return 0;
    



}