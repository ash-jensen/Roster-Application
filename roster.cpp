#include <iostream>
#include "roster.h"
using namespace std;

// Destructor
Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
	}
}

// Parse Student Data Table and Fill Vars, Call Add();
void Roster::ParseSDT(string studData) {

	// Parse & Set Vars
	int comma = studData.find(',');
	// Set studID;
	string studID = studData.substr(0, comma);
	int nextComma = studData.find(',', (comma + 1));
		
	// Set firstName
	string firstName = studData.substr((comma + 1), ((nextComma - 1) - comma));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));
		
	// Set lastName
	string lastName = studData.substr((comma + 1), ((nextComma - 1) - comma));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set emailAddress
	string emailAddress = studData.substr((comma + 1), ((nextComma - 1) - comma));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set age
	int age = stoi(studData.substr((comma + 1), ((nextComma - 1) - comma)));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set daysToComp1
	int daysToComp1 = stoi(studData.substr((comma + 1), ((nextComma - 1) - comma)));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set daysToComp2
	int daysToComp2 = stoi(studData.substr((comma + 1), ((nextComma - 1) - comma)));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set daysToComp3
	int daysToComp3 = stoi(studData.substr((comma + 1), ((nextComma - 1) - comma)));
	comma = nextComma;
	nextComma = studData.find(',', (comma + 1));

	// Set degreeProgString and find DegreeProgram type
	string degreeProgString = studData.substr((comma + 1), ((nextComma - 1) - comma));
	DegreeProgram degreeProgram = SECURITY;
	if (degreeProgString.at(degreeProgString.length() - 1) == 'Y') {
		degreeProgram = SECURITY;
	}
	else if (degreeProgString.at(degreeProgString.length() - 1) == 'K') {
		degreeProgram = NETWORK;
	}
	else {
		degreeProgram = SOFTWARE;
	}

	// Add() function call 
	Add(studID, firstName, lastName, emailAddress, age, daysToComp1, daysToComp2, daysToComp3, degreeProgram);
}

// Add() function to get student objects and put into an array;
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {

	// Populate daysInCourse array
	int daysToComp[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	// Create student object and add to array
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComp, degreeProgram);
}

// Remove() Function to Delete by Student ID;
void Roster::Remove(string studentID) {
	bool isFound = false;
	cout << "Attempting to remove student " << studentID << "..." << endl;
	for (int i = 0; i < lastIndex; ++i) {
		if (studentID == classRosterArray[i]->GetStudentID()) {
			isFound = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[i + 1];
			classRosterArray[i + 1] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			lastIndex--;
		}
	}
	if (isFound) {
			cout << studentID << " was removed." << endl;
	}
	else {
		cout << "ERROR: Student " << studentID << " not found." << endl;
	}
	cout << endl;
}

// PrintAll() FUnction to Print Out All Students in ClassRosterArray;
void Roster::PrintAll() {
	cout << "All Students:" << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		classRosterArray[i]->Print();
	}
	cout << endl;
}

// PrintAverageDaysInCourse() function that prints the average days until a course is completed per studentID;
void Roster::PrintAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; ++i) {
		if (studentID == classRosterArray[i]->GetStudentID()) {
			int avg = 0;
			avg = (classRosterArray[i]->GetDaysToComp()[0] + classRosterArray[i]->GetDaysToComp()[1] + classRosterArray[i]->GetDaysToComp()[2]) / 3;
			cout << "Average number of days to complete a course for student " << studentID << ": " << avg << endl;
		}
	}
}

// PrintInvalidEmails() Function to validate email addresses and print invalid email addresses;
void Roster::PrintInvalidEmails() {
	cout << "Invalid email(s): " << endl;
	for (int i = 0; i < numStudents; ++i) {
		string eToCheck;
		bool invalidE = false;
		eToCheck = classRosterArray[i]->GetEmailAddress();
		for (int j = 0; j < eToCheck.length(); ++j) {
			if (((eToCheck.find('@') == string::npos) || (eToCheck.find('.') == string::npos)) || (eToCheck.find(' ') != string::npos)) {
				invalidE = true;
			}
		}
		if (invalidE) {
			cout << eToCheck << endl;
		}
	}
	cout << endl;
}

// PrintByDegreeProgram() Function that takes degreeProgram type and prints each student that matches;
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in the " << degreeProgramStrings[degreeProgram] << " degree program: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (degreeProgram == classRosterArray[i]->GetDegreeProg()) {

			classRosterArray[i]->Print();
		}
	}
	cout << endl;
}
