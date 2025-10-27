#include "Library.h"
#include <print>
int main() {
    Library myLibrary;
  
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction");
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960, "Fiction");
    Book book3("1984", "George Orwell", 1949, "Dystopian");
    Book book4("Brave New World", "Aldous Huxley", 1932, "Dystopian");
    Book book5("The Catcher in the Rye", "J.D. Salinger", 1951, "Fiction");
    Book book6("Fahrenheit 451", "Ray Bradbury", 1953, "Dystopian");
    Book book7("Animal Farm", "George Orwell", 1945, "Satire");
    Book book8("Little Red Riding Hood", "Brothers Grimm", 1812, "Fiction");
    Book book9("The Hobbit", "J.R.R. Tolkien", 1937, "Fantasy");
    Book book10("Game of Thrones", "George R.R. Martin", 1996, "Fantasy");
    


    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);
    myLibrary.addBook(book4);
    myLibrary.addBook(book5);
    myLibrary.addBook(book6);
    myLibrary.addBook(book7);
    myLibrary.addBook(book8);
    myLibrary.addBook(book9);
    myLibrary.addBook(book10);


    myLibrary.displayAllBooks();

    
    myLibrary.remove_book("Brave New World");
    myLibrary.remove_book("To Kill a Mockingbird");

    std::print("\nAfter removing some books:\n");
    myLibrary.displayAllBooks();

    std::print("\nFiction Books:\n");
    auto fictionBooks = myLibrary.get_books_by_genre("Fiction");
    for (const auto& book : fictionBooks) {
        book.displayInfo();
    }
    

    std::print("\nBooks by Author, George Orwell:\n");
    auto orwellBooks = myLibrary.get_books_by_author("George Orwell");
    for (const auto& book : orwellBooks) {
        book.displayInfo();
    }

    std::print("\nBooks published after 1950:\n");
    auto recentBooks = myLibrary.get_books_after_year(1950);
    for (const auto& book : recentBooks) {
        book.displayInfo();
    }

    std::print("\nBooks in Genre 'Fiction' sorted by Year in ascending order:\n");
    myLibrary.displayBooksByGenreSortedByYear("Fiction");

    return 0;

}