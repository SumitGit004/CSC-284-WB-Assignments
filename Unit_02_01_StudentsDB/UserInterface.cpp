#include <print>
#include <iostream>
#include <format>
#include "StudentsRecordManager.h"
using namespace std;

int displayMenu();
Student getStudentDetails();
int getPositiveNumber();
void displayAllStudents(StudentsRecordManager &recordManager);
void showStudentCountByMajor(StudentsRecordManager &recordManager);
void printStudentDetails(const Student &student);
void DisplayStudentById(StudentsRecordManager &recordManager);
void DisplayStudentByName(StudentsRecordManager &recordManager);

int main()
{
    StudentsRecordManager recordManager;
    int userChoice;
    
    do{
    userChoice = displayMenu();
    switch (userChoice)
    {
    case 1:
        recordManager.addStudent(getStudentDetails());
        std::println("\nStudent added successfully to the record.");
        break;
    case 2:
        displayAllStudents(recordManager);
        break;
    case 3:
        DisplayStudentById(recordManager);
        break; 
       
    case 4:
        DisplayStudentByName(recordManager);
        break;

    case 5:
        showStudentCountByMajor(recordManager);
        break;

    case 6:
        println("\nExiting the program!");
        break;

    default:
        println("\nInvalid choice, try again please.");
        break;
    }
}while(userChoice != 6);

  return 0;
}

int displayMenu()
{

    int choice;

    println("\n\nPlease choose an option:");
    println("1. Add Student");
    println("2. Display All Students");
    println("3. Search by ID");
    println("4. Search by Name");
    println("5. Count Students by Major");
    println("6. Exit Program");
    print("Enter your choice (1-6): ");

    cin >> choice;
    cin.ignore(100,'\n');

    println();
    
    return choice;
}

Student getStudentDetails()
{
    int id, age;
    string name, major, email;

    print("\nEnter student id number:");
    id = getPositiveNumber();
    

    print("Enter student name: ");
    getline(cin, name);

    print("Enter student age (number only):");
    age = getPositiveNumber();

    print("Enter student major: ");
    getline(cin, major);

    print("Enter student email: ");
    getline(cin, email);

    return Student(id, name, age, major, email);
}

int getPositiveNumber()
{
    int number;
    cin >> number;
    cin.ignore(100,'\n');

    while (number <= 0)
    {
        print("Please enter a positive value: ");
        cin >> number;
        cin.ignore(100,'\n');
    }
    return number;
}

void displayAllStudents(StudentsRecordManager &recordManager)
{

    const vector<Student> &studentList = recordManager.getAllRecords();

    if (studentList.empty())
    {
        println("\nNo student records available");
    }
    else
    {
        int width = 5;

        string header = format("{:<{}} {:<{}} {:<{}} {:<{}} {:<{}}", "ID", width, "Name", width * 5, "Age", width, "Major", width * 4, "Email", width * 6);
        println("All students in the records\n");
        println("{}", header);
        println("{:-<{}}", '-', 14 * width);

        for (const Student &std : studentList)
        {
            string studentInfo = format("{:<{}} {:<{}} {:<{}} {:<{}} {:<{}}",
                                        std.getId(), width, std.getName(), width * 5, std.getAge(), width,
                                        std.getMajor(), width * 4, std.getEmail(), width * 6);
            println("{}", studentInfo);
        }
    }
}

void showStudentCountByMajor(StudentsRecordManager &recordManager)
{
    const map<string, int> &majorCount = recordManager.countMajor();

    if (majorCount.empty())
    {
        println("\nStudent records is empty.");
    }
    else
    {
        println("\nStudent Count by Major:");
        for (auto &pair : majorCount)
        {
            println("{}: {}", pair.first, pair.second);
        }
    }
}

void printStudentDetails(const Student &student)
{
    println("\nID: {} Name: {} Age: {} Major: {} Email: {}",
            student.getId(), student.getName(), student.getAge(), student.getMajor(), student.getEmail());
}

void DisplayStudentById(StudentsRecordManager &recordManager){

    print("\nEnter student id to search: ");
    int id = getPositiveNumber();

    Student *student = recordManager.searchById(id);
        if (student){
            printStudentDetails(*student);
        }
        else
            println("\nStudent with ID {} not found.", id);
}

void DisplayStudentByName(StudentsRecordManager &recordManager){
        
        string name;

        print("\nEnter student name to search: ");
        getline(cin, name);

        vector<Student> students = recordManager.searchByName(name);
        if (!students.empty())
        {
            println("\nStudents found with name '{}':", name);
            for (const Student &student : students){
                printStudentDetails(student);
            }
        }
        else
            println("\nNo students found with name '{}'.", name);
}