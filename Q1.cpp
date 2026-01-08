#include<iostream>
#include<string>
#include<cmath>
using namespace std;

// Function prototypes
void Welcome();
bool isPower(int);
void roof(int);
void body(int, int);

int main(){
    // Define user's name and user's yes/no answer as string variables
    string name,answer; 

    // Define the height and the width of the house as integer variables; counter to count the houses
    int height,width,counter=0;   

    // Show the welcome message
    Welcome();  

    // Get user's name
    cout<<"\nWhat is your name? ";
    cin>>name;

    // Greet user with their name
    cout<<"Well "<<name<<", welcome to the house drawing program."<<endl;

    // Ask user if they want a house
    cout<<"Do you want me to draw a simple house for you? (yes/no) ";
    cin>>answer;
    
    while(answer == "yes"){
        // Ask user to enter height
        cout<<"\n\tEnter the height of the house you want me to draw: ";
        cin>>height;

        // Give the user 2 tries
        for(int i = 1; i <= 2; i++){ 
            cout<<"\tPlease enter a number that is power of 2 for the width of the house (must be bigger than 4): ";
            cin>>width;

            // Check if the user has entered a suitable number, first try
            if((width <= 4) || !(isPower(width))){ 

                // Check if width being smaller than 4 is the problem
                if(width <= 4){ 
                    
                    // Put the enter if it's the second try, accoring to the sample output
                    if(i == 2) 
                        cout<<"\n\tYou enter "<<width<<" for the width. Smaller than 4!\n\n";
                    else
                        cout<<"\tYou enter "<<width<<" for the width. Smaller than 4!\n\n";
                    
                    // If it was the first try, go to the second try
                    if (i == 1) 
                        continue; 

                    // If it was the second try, end program
                    else{ 
                        cout<<"\tit seems you are having troubles entering even numbers! Program ends now."<<endl;
                        return 0;
                    }
                    }

                // If the problem is not that the width is too small, then the problem is that it is not a power of 2
                else{ 
                    
                    // Put the enter if it's the second try, according to the sample output
                    if (i == 2) 
                        cout<<"\n\tYou enter "<<width<<" for the width. Not power of 2!\n\n"; 
                    else
                        cout<<"\tYou enter "<<width<<" for the width. Not power of 2!\n\n";
                    
                    // If it was the first try, go to the second try
                    if (i == 1) 
                        continue; 
                    
                    // If it was the second try, end program
                    else{ 
                        cout<<"\tit seems you are having troubles entering even numbers! Program ends now."<<endl;
                        return 0;
                    }
                }
                
            }

            // If there is no problem with the user input, continue to draw the house
            else{break;} 
                
        }
    cout<<"\n\n";

    // Draw the roof
    roof(width); 

    // Draw the body
    body(height, width); 

    // Add one to the counter of the number of houses after a house has been built
    counter++; 

    // Ask the user if they want another house
    cout<<"\nDo you want me to draw a simple house for you? (yes/no) "; 
    cin>>answer;
    }

// If the user has only built one house
if (counter == 1) 
    cout<<"\nHope you like your one\n\nhouse!"; // Format according to the sample output

// If the user has built more than one house
else if(counter > 1) 
    cout<<"\nHope you like your "<<counter<<"\n\nhouses!";  // Format according to the sample output
return 0;
}
// Function to show the welcome message
void Welcome(){
    cout<<"\n";
    cout<<"---------------------------------------------------------"<<endl;
    
    // Put 11 spaces before the text
    for(int i = 0; i <= 10; i++){ 
        cout<<" ";
    }
    cout<<"House Drawing Program"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
}

// Function to see if an integer is a power of 2
bool isPower(int a){
    while(a % 2 == 0){
        // Keep dividing by 2 while it's even
        a /= 2; 
    }

    // If a has reached 1, that means it was a power of 2. otherwise, it's not
    return a == 1; 

}

// Function to draw the roof of the house
void roof(int width){
    int a = log2(width); // Number of rows of the roof
    int b = pow(2, a - 1) - 1;  // Number of spaces required for each row
    int c = 2;
    for(int i = 1; i <= a; i++){ // Number of rows: log2 of the width
        for(int j = 1; j <= b; j++){ // Put spaces
            cout<<" ";
        }
        for(int j = 1; j <= c; j++){ // Put #s
            cout<<"#";
        }
    c *= 2; // Ddjust the number of # for next line
    b -= pow(2, i - 1); // Adjust number of spaces for next line
    cout<<"\n";

    }
}

// Function to draw the body of the house
void body(int height, int width){
    for(int i = 1; i <= height; i++){ // Height equals number of rows of walls
        cout<<"|";
        for(int j = 1; j <= width-2; j++){ // Width-2 is the number of spaces
            cout<<" ";
        }
        cout<<"|\n";
    }
    for(int i = 1; i <= width; i++){  // Width is the number of '-'s in the last row of the body
        cout<<"-";
    }
    cout<<"\n\n";

}