#pragma once
#include "degree.h"
//#include "roster.h"
#include <iostream>
using namespace std;

class Student {
public:
	// Variables
	const static int daysToCompSize = 3;

	// Constructor w/ ALL Parameters
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComp[], DegreeProgram degreeProg);

	// Destructor
	~Student();

	// Setter Functions
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysToComp(int daysToComp[]);
	void SetDegreeProg(DegreeProgram degreeProg);

	// Getter Functions
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysToComp();
	DegreeProgram GetDegreeProg();

	// Other Functions
	void Print();

private:
	// Variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComp[daysToCompSize];
	DegreeProgram degreeProg;

};