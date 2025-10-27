#include"Book.h"
#include <print>

Book::Book(std::string title, std::string author, int year, std::string genre)
    : title(title), author(author), year(year), genre(genre) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

std::string Book::getGenre() const {
    return genre;
}

void Book::displayInfo() const{
  std::print("{} by {} ({}) [{}]\n", title, author, year, genre);
}

