#pragma once

#include "Book.h"
#include <vector>

class Library{
    private:
    std::vector<Book> books;

    public:
    void addBook(const Book& book);

    void remove_book(const std::string& title);

    Book find_book(const std::string& title) const;

    std::vector<Book> get_books_by_author(const std::string& author) const;

    std::vector<Book> get_books_by_genre(const std::string& genre) const;

    std::vector<Book> get_books_after_year(int year) const;

    void displayAllBooks() const;

    void displayBooksByGenreSortedByYear(const std::string&genre) const;

};
