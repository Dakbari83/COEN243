#include<iostream>
using namespace std;
int main(){
    int binary, decimal;
    cout<<"Enter 4-bit binary number: ";
    cin>>binary;
   
    int digit1 = (binary/1000)%10;
    int digit2 = (binary/100)%10;
    int digit3 = (binary/10)%10;
    int digit4 = binary%10;
     if ((binary/10000)!=0 || digit1>1 || digit2>1 || digit3>1 || digit4>1)
        cout<<"invalid binary number";
    else{
        
decimal = digit1 * 8 + digit2 * 4 + digit3 * 2 + digit4;
cout<<digit1<<digit2<<digit3<<digit4<<"b=";
switch(decimal){
    case 0:
    cout<<"0";
    break;
    case 1:
    cout<<"1";
    break;
    case 2:
    cout<<"2";
    break;
    case 3:
    cout<<"3";
    break;
    case 4:
    cout<<"4";
    break;
    case 5:
    cout<<"5";
    break;
    case 6:
    cout<<"6";
    break;
    case 7:
    cout<<"7";
    break;
    case 8:
    cout<<"8";
    break;
    case 9:
    cout<<"9";
    break;
    case 10:
    cout<<"A";
    break;
    case 11:
    cout<<"B";
    break;
    case 12:
    cout<<"C";
    break;
    case 13:
    cout<<"D";
    break;
    case 14:
    cout<<"E";
    break;
    case 15:
    cout<<"F";
    break;
    
}
cout<<"H";
    }
return 0;

}