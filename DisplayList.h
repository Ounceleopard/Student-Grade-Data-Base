#include "Student.h"
#include <list>
#include <string>
#include <iomanip> // Display in menu 

class StudentList 
{
private:
	list<Student>* SList; // linked list of student
public:
	StudentList(); // Constructor
	~StudentList(); // Destructor
	void addStudent(); // Adding 'New'
	void removeStudent(); // Removing 'Old'
	void updateGrade(); // New grade
	void search(); // Look for student in database
	void display(); 
};
