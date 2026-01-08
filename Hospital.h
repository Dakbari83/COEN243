#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "Doctor.h"

#include <vector>

class Hospital{
    private: 
        vector <Patient> * patients; // Vector to store patients
        vector <Doctor> * doctors; // Vector to store doctors

    public: 
        Hospital(); // Constructor
        ~Hospital(); // Destructor to free memory

        void Find_Oldest_Patient();
        int Count_Critical_Patients();
        void Doctors_By_Specialty();
        void Show_Patient_by_ID(long int);
        void Show_Doctor_by_ID(long int);
        void Show_assigned_doctor(long int);
        void Show_Assigned_Patients(long int);


};

#endif