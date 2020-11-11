#include "Student.h"

Student::Student(string name, char grade) 
{
	// Initialize members with pointer (this ->) stores address of current object
	this-> name = name;
	this-> grade = grade;
}

string Student::getName() 
{
	return name;
}

char Student::getGrade() 
{
	return grade;
}
void Student::setGrade(char grade) 
{
	this-> grade = grade; // Call function from Student; Looks back to grade location
}