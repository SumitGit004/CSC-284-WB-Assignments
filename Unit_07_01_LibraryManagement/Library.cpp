#include "Library.h"
#include <ranges>
#include <algorithm>
#include <print>

void Library::addBook(const Book& book) {
    books.push_back(book);
}


void Library::remove_book(const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(),
                [&title](const Book& book) {
                    return book.getTitle() == title;
                }), books.end());
}

//finds a book by the given title
Book Library::find_book(const std::string& title) const {
   auto it = std::find_if(books.begin(), books.end(),
                [&title](const Book& book) {
                    return book.getTitle() == title;
                });
   if (it != books.end()) {
       return *it;
   }
   throw std::runtime_error("Book not found"); 

} 

//returns a vector of Book by the given author
std::vector<Book> Library::get_books_by_author(const std::string& author) const {
    std::vector<Book> result;
   
    std::vector<Book>::const_iterator it;
    for (it = books.begin(); it != books.end(); it++) {
        if ((*it).getAuthor() == author) {
            result.push_back(*it);
        }
    }
    return result;
}

//returns a vector of Book by the given genre using std::ranges

std::vector<Book> Library::get_books_by_genre(const std::string& genre) const {
   
    auto filtered_books = std::ranges::views::filter(books, [&genre](const Book& book) {
        return book.getGenre() == genre;
    });
   
    //convert the filtered view to a vector
    std::vector<Book> result = std::ranges::to<std::vector<Book>>(filtered_books);

    return result;
    
}

//returns a vector of Book published after a certain year using std::ranges
std::vector<Book> Library::get_books_after_year(int year) const {
   
    auto filtered_books = std::ranges::views::filter(books, [year](const Book& book) {
        return book.getYear() > year;
    });
   
    //convert the filtered view to a vector
    std::vector<Book> result = std::ranges::to<std::vector<Book>>(filtered_books);
    return result;
}


//displays all books in the library using std::vector::iterator
void Library::displayAllBooks() const {
   
    std::vector<Book>::const_iterator it;

    for (it = books.begin(); it != books.end(); it++) {
        (*it).displayInfo();
    }
}


//displays books of a specific genre sorted by year using std::ranges::sort and std::ranges::transform
void Library::displayBooksByGenreSortedByYear(const std::string& genre) const {

    std::vector<Book> genre_books = get_books_by_genre(genre);
    
    //sorts the books by year in ascending order
    std::ranges::sort(genre_books, {}, &Book::getYear);

    std::vector<std::string> bookTitles(genre_books.size());
    
    std::ranges::transform(genre_books, bookTitles.begin(), [](const Book& book) {
        return book.getTitle();
    });


    std::print("Books of genre '{} \n", genre);

    for(const std::string& title : bookTitles) {
        std::print("{}\n", title);
    }
}





