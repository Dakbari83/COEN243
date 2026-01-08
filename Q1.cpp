#include<iostream>
#include<vector>
#include<array>
using namespace std;

// Function prototypes
vector<vector<double>> highest(vector<double>,int);
double median(vector<double>,int);
vector<vector<double>> mode(vector<double>,int);
array<int,5> dis(vector<double>,int);

int main(){
    int N;
    double e;
    cout<<"Enter number of grades: ";
    cin>>N;

    // If the user input is invalid, end program
    if(N<=3){
        cout<<"You should enter at least 4 grades.";  
        return 1;}

    vector<double> grades(N);

    cout<<"Now enter the grades: ";
    for(size_t i=0;i<N;i++){ // Fill the vector with user inputs
        cin>>e;
        grades.at(i)=e;
    }
    //Check if all the grades make sense
    for(double i : grades)
        if (!(i>=0 && i<=100)){
            cout<<"All grades should be between 0-100!"<<endl;
            return -1;}

   // Show the three highest grades and indices
    // Get the top 3 highest grades and their indices
    vector<vector<double>> result = highest(grades, N);

    // Print the highest grades and corresponding indices
    cout << "The highest grade is " << result[0][0] << " by student indice(s): ";
    for (double i : result[1]) {
        cout << i << " ";
    }
    cout << endl;

    cout << "The second highest grade is " << result[0][1] << " by student indice(s): ";
    for (double i : result[2]) {
        cout << i << " ";
    }
    cout << endl;

    cout << "The third highest grade is " << result[0][2] << " by student indice(s): ";
    for (double i : result[3]) {
        cout << i << " ";
    }
    cout << endl;

    
    // Show median
    cout<<"The median is: "<<median(grades,N)<<endl;; 
    
    // Show most frequently occuring grades
    // Get the mode and its frequency
    vector<vector<double>> results = mode(grades, N);
    // Print the elements with the highest frequency
    cout << "Element(s) with the highest frequency: ";
    for (double element : results[0]) {
        cout << element << " ";
    }
    cout << endl;
    // Print the frequency
    cout << "Frequency: " << results[1][0] << endl;
    
     // Show grade distribution
    cout<<"Number of A grades: "<<dis(grades,N).at(0)<<endl;
    cout<<"Number of B grades: "<<dis(grades,N).at(1)<<endl;
    cout<<"Number of C grades: "<<dis(grades,N).at(2)<<endl;
    cout<<"Number of D grades: "<<dis(grades,N).at(3)<<endl;
    cout<<"Number of F grades: "<<dis(grades,N).at(4)<<endl;
    return 0;



}


vector<vector<double>> highest(vector<double> grades, int N) {
    vector<int> indices1, indices2, indices3; // Store indices for the top 3 grades
    double m1 = -1, m2 = -1, m3 = -1;         // Initial values for highest grades (assuming non-negative grades)

    // First pass: Find the highest grade and its indices
    for (int i = 0; i < N; i++) {
        if (grades.at(i) > m1) {
            m1 = grades.at(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (grades.at(i) == m1) {
            indices1.push_back(i);
        }
    }

    // Second pass: Find the second highest grade and its indices
    for (int i = 0; i < N; i++) {
        if (grades.at(i) > m2 && grades.at(i) < m1) {
            m2 = grades.at(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (grades.at(i) == m2) {
            indices2.push_back(i);
        }
    }

    // Third pass: Find the third highest grade and its indices
    for (int i = 0; i < N; i++) {
        if (grades.at(i) > m3 && grades.at(i) < m2) {
            m3 = grades.at(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (grades.at(i) == m3) {
            indices3.push_back(i);
        }
    }

    // Create the return array
    vector<vector<double>> result(4); // 1 row for grades, 3 rows for their indices

    // First vector stores the three highest grades
    result[0] = {m1, m2, m3};

    // Convert indices to double to store in the same structure
    for (int i : indices1) result[1].push_back(i);
    for (int i : indices2) result[2].push_back(i);
    for (int i : indices3) result[3].push_back(i);

    return result;
}

vector <double> sort(vector<double> grades,int N){ //bubble sort
    double hold;
    for(size_t pass{0}; pass < N -1 ; pass++)
        for(size_t j{0}; j< N-pass-1; j++)
            if(grades.at(j)>grades.at(j+1)){
                hold=grades.at(j);
                grades.at(j)=grades.at(j+1);
                grades.at(j+1)=hold;
            }
    return grades;
}
double median(vector<double> grades,int N){
    if((N%2)==0) // If the vector size is even
        return (sort(grades,N).at(N/2)+sort(grades,N).at(N/2-1))/2.0; // The median is the average of the two middle elements
    else // If the vector size is odd
        return sort(grades,N).at(N/2); // The middle element of the sorted vector is the median
}

vector<vector<double>> mode(vector<double> grades, int N) {
    vector<int> n(N);
    int maxFrequency = 0;

    // Calculate frequency of each element
    for (int i = 0; i < N; i++) {
        int count = 1;  // Start with count 1 for the current element
        for (int j = i + 1; j < N; ++j) {
            if (grades.at(i) == grades.at(j)) {
                count++;
            }
        }
        n.at(i) = count;
        if (count > maxFrequency) {
            maxFrequency = count;  // Update max frequency
        }
    }

    // Find elements with the highest frequency
    vector<double> mostFrequentElements;
    for (int i = 0; i < N; ++i) {
        if (n.at(i) == maxFrequency) {
            // Check if it's the first occurrence of the element to avoid duplicates
            bool isDuplicate = false;
            for (int k = 0; k < i; ++k) {
                if (grades.at(i) == grades.at(k)) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                mostFrequentElements.push_back(grades.at(i));
            }
        }
    }

    // Return array with most frequent elements and the frequency as the last element
    vector<vector<double>> result(2);
    result[0] = mostFrequentElements;     // Elements with the highest frequency
    result[1].push_back((double)maxFrequency);  // Frequency (cast to double)

    return result;
}

array<int,5> dis(vector<double> grades, int N){
    int A=0,B=0,C=0,D=0,F=0;
    for(int i=0;i<N;i++){
        if(grades.at(i)>=90)
            ++A;
        else if(grades.at(i)>=80)
            ++B;
        else if(grades.at(i)>=65)
            ++C;
        else if(grades.at(i)>=50)
            ++D;
        else
            ++F;
    }
    return array<int,5>{A,B,C,D,F};
    
}