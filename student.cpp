#include <iostream>
#include "student.h"
using namespace std;


// Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComp[], DegreeProgram degreeProg) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysToCompSize; ++i) {
		this->daysToComp[i] = daysToComp[i];
	}
	this->degreeProg = degreeProg;
}

// Destructor
Student::~Student() {}

// Setter Functions
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysToComp(int daysToComp[]) {
	for (int i = 0; i < daysToCompSize; ++i) {
		this->daysToComp[i] = daysToComp[i];
	}
}

void Student::SetDegreeProg(DegreeProgram degreeProg) {
	this->degreeProg = degreeProg;
}


// Getter Functions
string Student::GetStudentID() {
	return this->studentID;
}

string Student::GetFirstName() {
	return this->firstName;
}

string Student::GetLastName() {
	return this->lastName;
}

string Student::GetEmailAddress() {
	return this->emailAddress;
}

int Student::GetAge() {
	return this->age;
}

int* Student::GetDaysToComp() {
		return this->daysToComp;
}

DegreeProgram Student::GetDegreeProg() {
	return this->degreeProg;
}


// Other Functions
void Student::Print() {
	cout << this->GetStudentID() << '\t';
	cout << "First Name: " << this->GetFirstName() << '\t';
	cout << "Last Name: " << this->GetLastName() << '\t';
	cout << "Age: " << this->GetAge() << '\t';
	cout << "daysInCourse: {";
	for (int i = 0; i < daysToCompSize; ++i) {
		if (i == (daysToCompSize - 1))
			cout << this->GetDaysToComp()[i];
		else {
			cout << this->GetDaysToComp()[i] << ", ";
		}
	 }
	cout << "}" << '\t';
	cout << "Degree Program: " << degreeProgramStrings[this->GetDegreeProg()] << endl;
}

  

