#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,sum=0;
    cout<<"Enter the array size n (the array will be an n*n square matrix): "; // Prompt the user to enter array size
    cin>>n; // Get the array size from the user
    
    // Use of vector because it's dynamic size unlike regular arrays
    vector<vector<int> > a(n,vector<int>(n)); // Initialize a two dimensional array with n rows and n columns 

    cout<<"Now enter the array elements row by row: "<<endl; // Prompt the user to enter array elements

     for(size_t i = 0; i < n; i++){ // Iterate over the rows
        for(size_t j = 0; j < n; j++) // Iterate over the columns
            cin>>a[i][j];
        cout<<endl; // Go to the next line after the user finishes entering a row
    }

    for(size_t i = 0; i < n; i++) // Add the elements on the main diagonal of the matrix
        sum+=a[i][i];

    for(size_t i = 0 , j=n-1; i < n && j>=0; i++,j--) // Add the elements on the other diagonal of the matrix
        sum+=a[i][j];
         
   
    if((n%2)!=0) // If the array size is odd, subtract the middle element from sum because it has been added twice
        sum-=a[n/2][n/2];
   
    cout<<"The sum of two diagonals of the array is "<<sum<<" = "; // Display the sum
    for(size_t i = 0; i < n-1; i++) // Display the elements on the main diagonal, except the last one
        cout<<a[i][i]<<"+";
    cout<<a[n-1][n-1]<<"+"; // Display the last element on the main diagonal

    if((n%2)==0){ // If the array size is even, display all he elements on the other diagonal
        for(size_t i = 0 , j=n-1; i < n-1 && j>0; i++,j--) // Display the elements except the last one
            cout<<a[i][j]<<"+";
        cout<<a[n-1][0]<<"."<<endl;
    }

    else{ // If the array size is odd, display the elements on the other diagonal except the middle one
        for(size_t i = 0 , j=n-1; i < n/2 && j>n/2; i++,j--) // Display the elements before the middle one
            cout<<a[i][j]<<"+";
        for(size_t i = (n/2)+1 , j=(n/2)-1; i < n-1 && j>0; i++,j--) // Display the elements after the middle one, except the last one
            cout<<a[i][j]<<"+";
        cout<<a[n-1][0]<<"."<<endl;
    }

    return 0;
}

