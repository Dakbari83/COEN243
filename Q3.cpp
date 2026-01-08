#include<iostream>
#include<array>
#include<iomanip> // For setw

using namespace std;

bool isIdentity(array<array<int,4>,4>);
array<int,16> spiralOrder(array<array<int,4>,4>);

int main(){
    array<array<int,4>,4> a;
    int e;
    cout<<"You will be entering a two-dimensional array (4x4) of int numbers."<<endl;
    for(int i=0;i<4;i++){ // Get the 2*2 matrix from the user
        cout<<"Enter row "<<i+1<<": ";
        for(int j=0;j<4;j++){
            cin>>e;
            a[i][j]=e;
        }
     }

    for(int i=0;i<4;i++){ // Print the array
        for(int j=0;j<4;j++){cout<<setw(3)<<a[i][j];}
        cout<<endl;}

    if(isIdentity(a)) // Check if the matrix is an identity matrix
        cout<<"This is an identity matrix."<<endl;
    else
        cout<<"This is not an identity matrix."<<endl;

     // Print the spiral order
     cout<<"Spiral Order: ";
     for(int i=0;i<15;i++){
         cout<<spiralOrder(a).at(i)<<", ";
     }
     cout<<spiralOrder(a).at(15);
    return 0;
    
}

bool isIdentity(array<array<int,4>,4> a){
    if((a[0][0]==1 && a[1][1]==1 && a[2][2]==1 && a[3][3]==1)&&(a[0][1]==0 && a[0][2]==0 && a[0][3]==0 && a[1][0]==0 && a[1][2]==0 && a[1][3]==0 && a[2][0]==0 && a[2][1]==0 && a[2][3]==0 && a[3][0]==0 && a[3][1]==0 && a[3][2]==0))
        return true;
    else
        return false;
}

array<int,16> spiralOrder(array<array<int,4>,4> a){
    array<int,16> result {a[0][0],a[0][1],a[0][2],a[0][3],a[1][3],a[2][3],a[3][3],a[3][2],a[3][1],a[3][0],a[2][0],a[1][0],a[1][1],a[1][2],a[2][2],a[2][1]};
    return result;
}
