#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    if ((a%b)==0)
    cout<<a<<" is divisible by "<<b<<endl;
    else
    cout<<a<<" is not divisible by "<<b<<endl;
    if ((b%a)==0)
    cout<<b<<" is divisible by "<<a<<endl;
    else
    cout<<b<<" is not divisible by "<<a<<endl;
    cout<<"The absolute difference between the two numbers is "<<abs(a-b)<<"."<<endl;
    cout<<"The result of dividing "<<a<<" by "<<b<<" is "<<a/b<<" with a remainder of "<<a-((a/b)*b)<<"."<<endl;
    return 0;
}