#include "Student.h"
using namespace std; // applies to this file only

Student::Student(int id, const string &name, int age, const string &major, const string &email){
    this->id = id;
    this->name = name;
    this->age = age;
    this->major = major;
    this->email = email;
}

void Student::setId(int id){
    this->id = id;
}

int Student::getId() const{
    return id;
}

void Student::setName(const string& name){
    this->name = id;
}

const string&  Student::getName() const{
    return name;
}

void Student::setAge(int age){
    this->age = age;
}

int Student::getAge() const{
    return age;
}

void Student::setMajor(const string& major){
    this->major = major;
}

const string&  Student::getMajor() const{
    return major;
}

void Student::setEmail(const string& email){
    this->email = email;
}

const string&  Student::getEmail() const{
    return email;
}

