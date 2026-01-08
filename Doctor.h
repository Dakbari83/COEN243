#ifndef DOCTOR_H
#define DOCTOR_H    

#include <string>

using namespace std;

class Doctor{
    private:
        string First;
        string Last;
        long int doctorID;
        string specialty;
        int experience;
        double salary;
        double bonus;

    public:
        Doctor(); // Constructor

        // Getters and setters
        string getFirst();
        void setFirst(string);
        string getLast();
        void setLast(string);
        long int getDoctorID();
        void setDoctorID(long int);
        string getSpecialty();
        void setSpecialty(string);
        int getExperience();
        void setExperience(int);
        double getSalary();
        void setSalary(double);
        double getBonus();
        void setBonus(double);

        double Calculate_Salary();
        void Print_Doctor_Info();


};

#endif