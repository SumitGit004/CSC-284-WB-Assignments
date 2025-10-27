#pragma once

#include <string>

class Book{
    private:
    std::string title;
    std::string author;
    int year;
    std::string genre;

    public:

    Book(std::string title, std::string author, int year, std::string genre);

    std::string getTitle() const;

    std::string getAuthor() const;

    int getYear() const;

    std::string getGenre() const;

    void displayInfo() const;

};
