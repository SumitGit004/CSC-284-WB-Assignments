#include "StudentsRecordManager.h"
#include <format>
#include <map>
#include <print>

void StudentsRecordManager::addStudent(Student student){
    record.push_back(student);
}

 void StudentsRecordManager::addStudent(int id, std::string name, int age, std::string  major, std::string email){
    Student student{id, name, age, major, email };
    record.push_back(student);
}

const std::vector<Student>& StudentsRecordManager::getAllRecords() const {
 return record;
}

//returning a pointer in case a student is not found, to avoid throwing exception
// as not finding an student is expected here, so using exception doesn't make sense to me in this expected situation, 
//returning nullptr would indicate the student was not found.
//could replace linear search with something better for performance.

Student* StudentsRecordManager::searchById(int id){

    for (Student &student : record) {
        if (student.getId() == id)
            return &student;
    }
    return nullptr;
}

//string_view points to a string , it doesn't own the memory for it, basically a pointer to constant, avoids copying strings
// more than one student can have same name
 std::vector<Student> StudentsRecordManager::searchByName(std::string_view name){
    
    std::vector<Student>tempRecord;
    for(Student& student: record){
        if(student.getName() == name)
         tempRecord.push_back(student);
    }
    return tempRecord;
}

std::map<std::string, int> StudentsRecordManager::countMajor(){
    int count = 0;

    std::map<std::string, int> majorCount;

    for ( Student &student : record)
    {
        std::string studentMajor = student.getMajor();
        
        if(majorCount.contains(studentMajor)){
            majorCount[studentMajor]++;
        } else {
            majorCount[studentMajor] = 1;
        }
    }

    return majorCount;
}
