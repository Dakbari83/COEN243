#include "Patient.h"
#include <iostream>

using namespace std;

// Constructor
Patient::Patient(): first(""), last(""), ID(0), doctor(-1), birth(""), blood(""), diagnosis(""), admission(""), discharge("-1"){}

// Getters and setters
string Patient::getFirst(){
    return first;
}

void Patient::setFirst(string a){
    first = a;
}

string Patient::getLast(){
    return last;
}

void Patient::setLast(string a){
    last = a;
}

long int Patient::getID(){
    return ID;
}

void Patient::setID(long int a){
    ID = a;
}

long int Patient::getDoctor(){
    return doctor;
}

void Patient::setDoctor(long int a){
    doctor = a;
}

string Patient::getBirth(){
    return birth;
}

void Patient::setBirth(string a){
    birth = a;
}

string Patient::getBlood(){
    return blood;
}

void Patient::setBlood(string a){
    blood = a;
}

string Patient::getDiagnosis(){
    return diagnosis;
}

void Patient::setDiagnosis(string a){
    diagnosis = a;
}

string Patient::getAdmission(){
    return admission;
}

void Patient::setAdmission(string a){
    admission = a;
}

string Patient::getDischarge(){
    return discharge;
}

void Patient::setDischarge(string a){
    discharge = a;
}

bool Patient::IsDischarged(){ // Function to check if a patient is discharged
    if(discharge!="-1")
        return true;
    else
        return false;
}

string Patient::Patient_Status(){ // Function to check the patient's status

    // If the diagnosis contains the word "critical" or "Critical", return "Critical"
    if ((diagnosis.find("critical") != string::npos)||(diagnosis.find("Critical") != string::npos)) 
        return "Critical";
    
    // If the diagnosis is the word "moderate" or "Moderate", return "Moderate"
    else if ((diagnosis=="moderate")||(diagnosis=="Moderate")){
        return "Moderate";}

    // Else, return "Stable"
    else{
        return "Stable";}
    
}

void Patient::Print_Patient_Info(){ // Function to print all the patient info
    cout<<"Patient Info:"<<endl;
    cout<<"First Name: "<<first<<endl;
    cout<<"Last Name: "<<last<<endl;
    cout<<"ID: "<<ID<<endl;
    cout<<"Doctor ID: "<<doctor<<endl;
    cout<<"Birth Date: "<<birth<<endl;
    cout<<"Blood Type: "<<blood<<endl;
    cout<<"Diagnosis: "<<diagnosis<<endl;
    cout<<"Admission Date: "<<admission<<endl;
    cout<<"Discharge Date: "<<discharge<<endl;
    cout<<"Patient Status: "<<Patient_Status()<<endl;
    cout<<endl;
}