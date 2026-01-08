#include<iostream>
#include <string>

using namespace std;
string reverseString(string);
string decodeLanguage(string);

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    string result = decodeLanguage(s);
    cout << "Decoded string: " << result << endl;
    return 0;
}
// Function to reverse a given substring
string reverseString(string str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

// Recursive function to decode the string by handling nested parentheses
string decodeLanguage(string input) {
    size_t closePos = input.find(')');  // Find the first closing parenthesis
    if (closePos == string::npos) {
        // Base case: No closing parentheses left, return the input
        return input;
    }

    // Manually search for the last open parenthesis before the closing one
    int openPos = -1;
    for (int i = 0; i < closePos; ++i) {
        if (input[i] == '(') {
            openPos = i;  // Update openPos to the most recent '('
        }
    }

    if (openPos != -1) {
        // Reverse the content between the parentheses
        string toReverse = input.substr(openPos + 1, closePos - openPos - 1);
        string reversed = reverseString(toReverse);

        // Replace the part of the string with the reversed string and remove parentheses
        input = input.substr(0, openPos) + reversed + input.substr(closePos + 1);

        // Recursively call decodeLanguage on the updated string
        return decodeLanguage(input);
    }

    return input;  // In case no valid parentheses are found
}