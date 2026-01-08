#include "Hospital.h"
#include <iostream>
#include <fstream>
#include <stdexcept>  // For exception handling
#include <sstream>  // To handle string streams
using namespace std;

Hospital::Hospital() { // Constructor to read data from files and initialize the vectors
    patients = new vector<Patient>();  // Safely initialize patients pointer
    doctors = new vector<Doctor>();    // Safely initialize doctors pointer

    ifstream file1("patients_sample.txt"); // Open the patients' file
    ifstream file2("doctor_sample.txt"); // Open the doctors' file

    if (!file1) { // Check if the file is open
        cerr << "Error: Could not open the patients' file!" << endl; // Print an error message
        throw runtime_error("Unable to open patients_sample.txt"); // Throw an exception
    }

    if (!file2) { // Check if the file is open
        cerr << "Error: Could not open the doctors' file!" << endl; // Print an error message
        throw runtime_error("Unable to open doctor_sample.txt"); // Throw an exception
    }

    string line;
    if (getline(file1, line)) { // Read the first line of the file
        int size = stoi(line);  // Get the number of patients
        cout << "Number of patients: " << size << endl;

        for (int i = 0; i < size; i++) { // Loop through the patients
            string firstt, lastt, bloodd, birthh, adm, dis;
            long int iddd, doctorr;
            string diagg;

            // Read first name, last name, ID, doctor ID, birth date, and blood type
            if (!(file1 >> firstt >> lastt >> iddd >> doctorr >> birthh >> bloodd)) { 
                cerr << "Error reading basic patient data at line " << i + 2 << endl; // Print an error message
                throw runtime_error("Error reading patient data. Check input file format."); // Throw an exception
            }

            // Handle the diagnosis, which is enclosed in quotation marks
            char quote;
            file1 >> quote;  // Skip the first quotation mark
            getline(file1, diagg, '"');  // Read until the closing quotation mark

            // Now, read the admission date and discharge date
            if (!(file1 >> adm >> dis)) {
                cerr << "Error reading admission/discharge data at line " << i + 2 << endl;
                throw runtime_error("Error reading admission/discharge data.");
            }

            cout << "Read patient: " << firstt << " " << lastt << " with diagnosis: " << diagg << endl;

            // Construct patient object
            Patient p;
            p.setFirst(firstt); // Set the first name
            p.setLast(lastt); // Set the last name
            p.setID(iddd); // Set the ID
            p.setDoctor(doctorr); // Set the doctor ID
            p.setBirth(birthh); // Set the birth date
            p.setBlood(bloodd); // Set the blood type
            p.setDiagnosis(diagg);  // Set the diagnosis
            p.setAdmission(adm); // Set the admission date
            p.setDischarge(dis); // Set the discharge date

            patients->push_back(p);  // Add patient to vector
        }



    } else {
        throw runtime_error("patients_sample.txt is empty or formatted incorrectly."); // Throw an exception
    }

    if (getline(file2, line)) { // Read the first line of the file
        int size2 = stoi(line);  // Get the number of doctors
        cout << "Number of doctors: " << size2 << endl;

        for (int i = 0; i < size2; i++) { // Loop through the doctors
            string firstt, lastt, spec;
            long int iddd;
            int exp;
            double sal, per;

            // Read first name, last name, and doctor ID
            if (!(file2 >> firstt >> lastt >> iddd)) {
                cerr << "Error reading basic doctor data at line " << i + 2 << endl;
                throw runtime_error("Error reading doctor data. Check input file format.");
            }

            // Read the first quotation mark and then the specialty inside the quotes
            char quote;
            file2 >> quote;  // Skip the first quotation mark
            getline(file2, spec, '"');  // Read until the closing quotation mark

            // Now, read the experience, salary, and bonus
            if (!(file2 >> exp >> sal >> per)) {
                cerr << "Error reading experience/salary/bonus data at line " << i + 2 << endl;
                throw runtime_error("Error reading experience/salary/bonus data.");
            }

            cout << "Read doctor: " << firstt << " " << lastt << " with specialty: " << spec << endl;

            // Construct doctor object
            Doctor d;
            d.setFirst(firstt); // Set the first name
            d.setLast(lastt); // Set the last name
            d.setDoctorID(iddd); // Set the doctor ID
            d.setSpecialty(spec);  // Set the specialty
            d.setExperience(exp); // Set the experience
            d.setSalary(sal); // Set the salary
            d.setBonus(per); // Set the bonus

            doctors->push_back(d);  // Add doctor to vector
        }


    } else {
        throw runtime_error("doctor_sample.txt is empty or formatted incorrectly.");
    }
}

// Destructor to clean up dynamically allocated memory
Hospital::~Hospital() {
    cout << "Cleaning up allocated memory..." << endl;
    delete patients;  // Free the allocated memory
    delete doctors;
    patients = nullptr;
    doctors = nullptr;
    cout << "Memory cleaned up." << endl;
}


void Hospital::Find_Oldest_Patient(){ // Function to find and print the information of the oldest patient
    int ye=3000,mo=13,da=40;
    Patient max; // A patient to assign the oldest patient to

    for(Patient p : *patients){ // Loop through the patients
        string year=p.getBirth().substr(0,4),month=p.getBirth().substr(4,2),day=p.getBirth().substr(6,2); // Strings of birth year, month and day
        int y = stoi(year), m = stoi(month), d = stoi(day); // Integers of birth year, month and day
        
        if(y<ye){ // Find the oldest birth year
            ye = y;
            max = p;
        }

        else if (y == ye){ // If two patients have the same birth year
            if(m < mo){ // Compare the birth months
                mo = m;
                max = p;
            }

            else if(m == mo){ // If two patients have the same birth year and month
                if(d<da){ // Compare the days of birth
                    da = d;
                    max = p;
                }
            }
        }

    }
    max.Print_Patient_Info(); // Print the oldest patient's info
}

int Hospital::Count_Critical_Patients() { // Function to count critical patients
    int c = 0;
    for (Patient p : *patients) {
        string diagnosis = p.getDiagnosis();
        // Ensure the diagnosis is case-insensitive and checks for the word "critical"
        if (diagnosis.find("critical") != string::npos || diagnosis.find("Critical") != string::npos) {
            c++;
        }
    }
    return c;
}


void Hospital::Doctors_By_Specialty() { //  Function to print all doctors' info with a certain specialty
    string sp;
    cout << "Enter the specialty you are looking for: ";
    getline(cin, sp); // Get the specialty from the user

    bool found = false; // Flag to check if any doctors were found
    for (Doctor d : *doctors) {
        if (sp == d.getSpecialty()) {  // Exact match for specialty
            d.Print_Doctor_Info(); // Print the doctor's info
            found = true;
        }
    }

    if (!found) { // If no doctors were found
        cout << "No doctors found with the specialty: " << sp << endl;
    }
}


void Hospital::Show_Patient_by_ID(long int i){ // Function to show patient info based on ID
    int a = 1;
   for(Patient p : *patients) // Loop through the patients
        if (p.getID() == i){ // If the patient ID matches the input ID
            p.Print_Patient_Info(); // Print the patient's info
            a = 0;
        }

    if(a) 
        cout<<"No patient has the provided ID"<<endl;

}

void Hospital::Show_Doctor_by_ID(long int i){ // Function to show doctor info based on ID
    int a = 1;
    for(Doctor d : *doctors) // Loop through the doctors
        if (d.getDoctorID() == i){ // If the doctor ID matches the input ID
            d.Print_Doctor_Info(); // Print the doctor's info
            a = 0;
        }
    if(a)
        cout<<"No doctor has the provided ID"<<endl;

}


void Hospital::Show_assigned_doctor(long int patientID) { // Function to show the assigned doctor to a patient
    for (Patient p : *patients) { // Loop through the patients
        if (p.getID() == patientID) { // If the patient ID matches the input ID
            if (p.getDoctor() == -1) { // If no doctor is assigned
                cout << "No doctor assigned" << endl;
                return;
            }

            // Find the assigned doctor
            for (Doctor d : *doctors) { // Loop through the doctors
                if (d.getDoctorID() == p.getDoctor()) { // If the doctor ID matches the assigned doctor ID
                    d.Print_Doctor_Info(); // Print the doctor's info
                    return;
                }
            }

            cout << "No doctor found with the ID: " << p.getDoctor() << endl;
            return;
        }
    }

    cout << "No patient found with the ID: " << patientID << endl;
}


void Hospital::Show_Assigned_Patients(long int doctorID) { // Function to show patients assigned to a doctor
    bool doctorFound = false; // Flag to check if the doctor was found
    bool patientFound = false; // Flag to check if any patients were found

    // Check if the doctor with the given ID exists
    for (Doctor d : *doctors) { // Loop through the doctors
        if (d.getDoctorID() == doctorID) { // If the doctor ID matches the input ID
            doctorFound = true; // Set the flag to true
            break;
        }
    }

    // If the doctor doesn't exist, print a message and return
    if (!doctorFound) {
        cout << "No doctor found with the ID: " << doctorID << endl;
        return;
    }

    // If the doctor exists, search for patients assigned to this doctor
    for (Patient p : *patients) { // Loop through the patients
        if (p.getDoctor() == doctorID) { // If the patient's assigned doctor matches the input ID
            p.Print_Patient_Info(); // Print the patient's info
            patientFound = true;
        }
    }

    // If no patients are assigned to this doctor, print a message
    if (!patientFound) {
        cout << "No patients assigned to this doctor." << endl;
    }
}
