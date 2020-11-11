/*
    Name: Student Grades 
    Copyright: Brayan Villatoro
    Author: Brayan Villatoro
    Date: 10/26/2020 8:00PM
    Description:

    CSCI-373 (FALL 2020) (Prof. Abdu) (Assignment 3) (John Jay College)
    -----------------------------------------------------------------------------------
    o Student Class 	  					  -Line 00- -DisplayList.h/.cpp- "Display list represents entire lecture options"
    o Add, Remove Students 					  -Line 00- 
    o Update, and search for student Grades   -Line 00- 
    o Grade Validation                        -Line 23- -DisplayList.cpp
    o Overload equality operator string class -Line 54- -DisplayList.cpp

    • 2 header files 	
    • 2 source files (implementation).
    • Main.cpp
*/
#include "DisplayList.h" // Contains functions for menu 

int main() 
{
    cout << "=================================================================================================\n";
    cout << "\tOnly enter grades 100 through 1, otherwise grade will be considered unknown '?'\n";
    cout << "(100 ~ 90 = A || 90 ~ 80 = B || 80 ~ 70 = C || 70 ~ 60 = D || 60 ~ 1 = F || Other grades = ?)\n";
    cout << "=================================================================================================\n";

    int option = 0; // Default NON-Selected 
    StudentList list; // create a ClassList object
    while (option != 6) // NON-Exit :: Display Options   
    {
        cout << "\n\t\tJohn Jay College of Criminal Justice : Student Database\n";
        cout << "\nSelect an option:\n\n";
        cout << "1: Add Student\n";
        cout << "2: Remove Student\n";
        cout << "3: Update Student grade\n";
        cout << "4: Search for a student\n";
        cout << "5: Display all Students\n";
        cout << "6: QUIT" << "\n\n";
        cout << "Enter your choice: ";
        cin >> option; // User input
 
        if (option < 1 || option > 6) // validation of user input 
        {
            cout << "ERROR! Please Try Again!" << endl;
            cout << "Number boundaries are limited to 1 to 6" << endl;
        }
        else {
            // Route of selected option :: (Case Switch statments also works) 
            if (option == 1) 
            {
                list.addStudent(); // Takes care of everything  
            }
            else if (option == 2) 
            {
                list.removeStudent();
            }
            else if (option == 3) 
            {
                list.updateGrade();
            }
            else if (option == 4) 
            {
                list.search();
            }
            else if (option == 5) 
            {
                list.display();
            }
            else 
            {
                cout << "Logging off" << endl;
            }
        }
    }
    return 0;
}