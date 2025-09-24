#pragma once

#include "Student.h"
#include <vector>
#include <map>

class StudentsRecordManager{
    private:
    std::vector<Student> record;
    
    public:
    void addStudent(Student student);
    void addStudent(int id, std::string name, int age,std::string  major,std::string email);
    const std::vector<Student>& getAllRecords() const;
    Student* searchById(int Id) ;
    std::vector<Student> searchByName(std::string_view name);
    std::map <std::string, int> countMajor();

};