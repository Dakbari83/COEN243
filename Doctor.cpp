#include "Doctor.h"
#include <iostream>

using namespace std;

// Constructor
Doctor::Doctor(): First(""), Last(""), doctorID(0), specialty(""), experience(0), salary(0), bonus(0)  {}

// Getters and setters
string Doctor::getFirst(){
    return First;
}

void Doctor::setFirst(string s){
    First = s;
}

string Doctor::getLast(){
    return Last;
}

void Doctor::setLast(string s){
    Last = s;
}

long int Doctor::getDoctorID(){
    return doctorID;
}

void Doctor::setDoctorID(long int b){
    doctorID = b;
}

string Doctor::getSpecialty(){
    return specialty;
}

void Doctor::setSpecialty(string s){
    specialty = s;
}

int Doctor::getExperience(){
    return experience;
}

void Doctor::setExperience(int i){
    experience = i;
}

double Doctor::getSalary(){
    return salary;
}

void Doctor::setSalary(double d){
    salary = d;
}

double Doctor::getBonus(){
    return bonus;
}

void Doctor::setBonus(double d){
    bonus = d;
}

double Doctor::Calculate_Salary(){ // Function to update the new salary based on the bonus percentage
    return salary * (1.0 + bonus); 
}

void Doctor::Print_Doctor_Info(){ // Function to print all the doctor info
    cout << "Doctor: " << First << " " << Last << endl;
    cout << "ID: " << doctorID << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Salary: " << salary << endl;
    cout << "Bonus: " << bonus << endl;
    cout << "Total salary: " << Calculate_Salary() << endl;
}