#include <iostream>
using namespace std;

// Requirement #1 
class Student 
{
private:
	string name; // Name 
	char grade; // Grades 
public:
	Student(string name, char grade); // Constructor
	string getName(); // Input student name 
	char getGrade(); // Input grade for student
	void setGrade(char grade); // New grade
};