// AJensen C867.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
	// Variables/Arrays/Classes 
	const int NUM_STUDENTS = 5;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ashley,Jensen,ajen147@wgu.edu,34,34,56,46,SOFTWARE"
	};
	Roster classRoster;

	// Course Title, Language Used, StudentID and Name
	cout << "Course Title: C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001250622" << endl;
	cout << "Name: Ashley Jensen" << endl;
	cout << endl;

	// Parse Student Data Table and Add to Roster;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		classRoster.ParseSDT(studentData[i]);
	}

	// Print Entire Array of Student Objects;
	classRoster.PrintAll();

	// Print Invalid Emails;
	classRoster.PrintInvalidEmails();

	// Print Average Days a Studnt Takes to Complete a Course;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (i == (NUM_STUDENTS - 1)) {
			classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
			cout << endl;
		}
		else if (i == 0) {
			cout << "Average Days to Complete Course:" << endl;
			classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
		}
		else {
			classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
		}
	}

	// Print Each Student by Given Degree Program;
	classRoster.PrintByDegreeProgram(SOFTWARE);

	// Remove Student by Student ID;
	classRoster.Remove("A3");

	// Print Entire Array of Student Objects;
	classRoster.PrintAll();

	// Remove Student by Student ID;
	classRoster.Remove("A3");

	return 0;
}