#pragma once

#include <string>
// Define a student class to model a student.
class Student{

    private:
    int id;//id should be const
    std::string name;
    int age;
    std::string major;
    std::string email;

    public:

    Student(int id, const std::string& name, int age, const std::string& major,const  std::string& email);
    
    void setId(int id);
    int getId() const;

    void setName(const std::string& name);
    const std::string& getName() const;

    void setAge(int age);
    int getAge() const;

    void setMajor(const std::string& major);
    const std::string& getMajor() const;

    void setEmail(const std::string& email);
    const std::string& getEmail() const;

    };