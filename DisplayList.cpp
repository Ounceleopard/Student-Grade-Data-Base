#include "DisplayList.h"

StudentList::StudentList() 
{
    SList = new list<Student>();
}

StudentList::~StudentList() 
{
    delete SList;
}

void StudentList::addStudent()
{
    // Ask user for student name
    cout << "Enter name of student: ";
    cin.ignore(); // Disable Enter to avoid skipping name input  
    string name;
    getline(cin, name); // User name input
    cout << "Enter grade(100~60): ";
    double grade;
    cin >> grade;
    //Grade validation A-F or ? unknown grade 
    {
        if (grade >= 90 && grade <= 100)
            grade = 'A';
        else if (grade >= 80 && grade < 90)
            grade = 'B';
        else if (grade >= 70 && grade < 80)
            grade = 'C';
        else if (grade >= 60 && grade < 70)
            grade = 'D';
        else if (grade >= 1 && grade < 60)
            grade = 'F';
        else if (grade > 100 && grade < 1000)
            grade = '?';
        else grade = '?';
    }
    Student s(name, grade); // Saving student data into list 
    SList->push_back(s); // Moving data through tree  
}

void StudentList::removeStudent() 
{
    cout << "Enter name of student: ";
    cin.ignore(); // Disable Enter Key
    string name;
    getline(cin, name); // User input
    // Check if student is removed
    bool sRemoved = false;
    // Check database  
    // create iterator
    list<Student>::iterator itr = SList->begin();
    for (int i = 0; i < SList->size(); i++) 
    {
        // check if student exist at curent location
        if (itr->getName().compare(name) == 0) 
        {
            list<Student>::iterator end = itr;
            end++;
            SList->erase(itr, end);
            sRemoved = true;
            break;
        }
        itr++;
    }
    // check if student is removed
    if (!sRemoved) 
    {
        cout << "Student is not in list!" << endl;
    }
}

void StudentList::updateGrade() 
{
    display();
    // Ask user to select id of student to update grade
    cout << "Eneter the student's number to update: " << endl;
    int id; // Student ID
    cin >> id; 
    // Valid ID true or false
    if (id < 1 || id > SList->size()) 
    {
        cout << "Invalid Student ID!" << endl;
    }
    else {
        // New Grade
        cout << "Enter New Grade(100~60): "; 
        double grade; 
        cin >> grade; 
        {
            if (grade >= 90 && grade <= 100)
                grade = 'A';
            else if (grade >= 80 && grade < 90)
                grade = 'B';
            else if (grade >= 70 && grade < 80)
                grade = 'C';
            else if (grade >= 60 && grade < 70)
                grade = 'D';
            else if (grade >= 1 && grade < 60)
                grade = 'F';
            else if (grade > 100 && grade < 1000)
                grade = '?';
            else grade = '?';
        }
        // Move student's data into database
        // Iterator
        list<Student>::iterator itr = SList->begin();
        for (int i = 1; i < id; i++) 
        {
            itr++;
        }
        // New Grade 
        itr->setGrade(grade);
    }
}

void StudentList::search() 
{
    // User student name input 
    cout << "Enter name of student: ";
    cin.ignore(); // Enter key disabled 
    string name;
    getline(cin, name); // Get user input
    // List search 
    bool sExist = false; // Create a marker to see if student found in search
    // Create iterator
    list<Student>::iterator itr = SList->begin();
    for (int i = 0; i < SList->size(); i++) 
    {
        // check if student exist at curent location
        if (itr->getName().compare(name) == 0) 
        {
            cout << "Name: " << itr->getName() << "\t" << "Grade: " << itr->getGrade() << endl;
            sExist = true; 
            break;
        }
        itr++;
    }
    // Confirms student's existance 
    if (!sExist) 
    {
        cout << "No Such Student Exist : Enter the name's row number" << endl;
    }
}

void StudentList::display() 
{
    cout << "\n=======================================\n";
    cout << setw(5) << left << "EMPLID ID: ";
    cout << setw(20) << left << "Name";
    cout << left << "Grade" << endl;
    cout << "=======================================\n";
    // Display all students
    // Create iterator
    list<Student>::iterator itr = SList->begin();
    for (int i = 0; i < SList->size(); i++) {
        cout << setw(5) << left << (i + 1);
        cout << setw(25) << left << itr->getName();
        cout << " " << left << itr->getGrade() << endl;
        itr++;
    }
    cout << "=======================================\n";
}