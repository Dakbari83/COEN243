#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient{
    private:
        string first;
        string last;
        long int ID;
        long int doctor;
        string birth;
        string blood;
        string diagnosis;
        string admission;
        string discharge;

    public:
        // Constructor
        Patient();

        // Getters and setters
        string getFirst();
        void setFirst(string);
        string getLast();
        void setLast(string);
        long int getID();
        void setID(long int);
        long int getDoctor();
        void setDoctor(long int);
        string getBirth();
        void setBirth(string);
        string getBlood();
        void setBlood(string);
        string getDiagnosis();
        void setDiagnosis(string);
        string getAdmission();
        void setAdmission(string);
        string getDischarge();
        void setDischarge(string);

        bool IsDischarged();
        string Patient_Status();
        void Print_Patient_Info();


};


#endif