#include "Hospital.h"
#include <iostream>
#include <exception>  // For exception handling

using namespace std;

void displayMenu() { // Display the main menu of the system
    cout << "\n=== Hospital Management System ==="<<endl;
    cout << "1. Find the oldest patient"<<endl;
    cout << "2. Count the number of critical patients"<<endl;
    cout << "3. Find doctors by specialty"<<endl;
    cout << "4. Show patient by ID"<<endl;
    cout << "5. Show doctor by ID"<<endl;
    cout << "6. Show the assigned doctor of a patient"<<endl;
    cout << "7. Show the assigned patients of a doctor"<<endl;
    cout << "8. Exit"<<endl;
    cout << "\nEnter your choice: ";
}

int main() {

    // Group project, members: Daniel Akbari, ID: 40298757; Md Rahitul Islam, ID: 40266280

    try {
        Hospital h;  // Try to create the Hospital object
        int choice;

        while (true){
            displayMenu();  // Display the main menu
            cin >> choice;  // Get user choice

            if (choice == 8) { // Exit the system if user chooses option 8
                cout << "Exiting the system.\n";
                break;
            }

            switch (choice) {

                case 1: {  // Find the oldest patient
                    cout << "\nFinding the oldest patient..." << endl;
                    h.Find_Oldest_Patient();
                    break;
                }

                case 2: {  // Count the number of critical patients
                    cout << "Counting critical patients..." << endl;
                    cout << "Number of critical patients: " << h.Count_Critical_Patients() << endl;
                    break;
                }

                case 3: {  // Find doctors by specialty
                    cin.ignore();
                    cout << "\nFinding doctors by specialty..." << endl;
                    h.Doctors_By_Specialty();
                    break;
                }

                case 4: {  // Show patient by ID
                    long int id;
                    cout << "Enter the ID of the patient you want to show: " << endl; // Prompt the user to enter an ID
                    cin >> id;
                    
                    cout << "Showing patient by ID..." << endl;
                    h.Show_Patient_by_ID(id);  
                    break;
                }

                case 5: {  // Show doctor by ID
                    long int ID;
                    cout<<"Enter the ID of the doctor you want to show: "<<endl; // Prompt the user to enter an ID
                    cin>>ID;
                    
                    cout << "Showing doctor by ID..." << endl;
                    h.Show_Doctor_by_ID(ID);   
                    break;
                }

                case 6: { // Show assigned doctor of a patient
                    long int iD;
                    cout << "Enter the ID of the patient you want to show the assigned doctor for: " << endl; // Prompt the user to enter an ID
                    cin >> iD;
                
                    cout << "Showing assigned doctor..." << endl;
                    h.Show_assigned_doctor(iD);
                    break;
                }

                case 7: { // Show assigned patients of a doctor
                    long int Id;
                    cout << "Enter the ID of the doctor you want to show the assigned patients for: " << endl; // Prompt the user to enter an ID
                    cin >> Id;

                    cout << "Showing assigned patients..." << endl;
                    h.Show_Assigned_Patients(Id);
                    break;
                }

                default:
                    cout << "\nInvalid choice. Please try again.\n";

            }
        
        
         }
    
        } 
        
     catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;  // Catch and print the exception
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;  // Catch any other exception
    } catch (...) {
        cerr << "An unknown error occurred." << endl;  // Catch any unknown errors
    }

    return 0;

}