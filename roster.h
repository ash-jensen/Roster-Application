#pragma once
#include <iostream>
#include "student.h" 
using namespace std;

class Roster {
	public:
		// Varriables/Arrays
		int lastIndex = -1;
		const static int numStudents = 5;
		Student* classRosterArray[numStudents];

		// Destructor
		~Roster();
	
		// Parse Student Data Table and Fill Vars, Call Add();
		void ParseSDT(string studData);

		// Add() function to get student objects and put into an array;
		void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, DegreeProgram degreeProgram);

		// Remove() Function to Delete by Student ID;
		void Remove(string studentID);

		// PrintAll() FUnction to Print Out All Students in ClassRosterArray;
		void PrintAll();

		// PrintAverageDaysInCourse() function that prints the average days until a course is completed per studentID;
		void PrintAverageDaysInCourse(string studentID);

		// PrintInvalidEmails() Function to validate email addresses and print invalid email addresses;
		void PrintInvalidEmails();

		// PrintByDegreeProgram() Function that takes degreeProgram type and prints each student that matches;
		void PrintByDegreeProgram(DegreeProgram degreeProgram);

	private:
		// Variables
		string studData;

};
