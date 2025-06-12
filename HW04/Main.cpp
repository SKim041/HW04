#include "HW04.h"
#include <iostream>

int main()
{
    BookManager book_m;
    book_m.addBook("å1-1", "�۰�1");
    book_m.addBook("å1-2", "�۰�1");
    book_m.addBook("å2-1", "�۰�2");
    book_m.displayAllBooks();

    BorrowManager borrow_m(book_m);
    
    borrow_m.initializeStock(book_m.getByTitle("å1-1"));
    borrow_m.initializeStock(book_m.getByTitle("å1-2"));
    borrow_m.initializeStock(book_m.getByTitle("å2-1"));
    borrow_m.initializeStock(book_m.getByTitle("å2-2"));

    borrow_m.displayStock();

    borrow_m.borrowBookByTitle("å1-1");
    borrow_m.borrowBookByTitle("å1-1");
    borrow_m.borrowBookByTitle("å1-1");
    borrow_m.borrowBookByTitle("å1-1");
    borrow_m.borrowBookByTitle("å1-2");

    borrow_m.displayStock();

    borrow_m.returnBook("å1-1");
    borrow_m.displayStock();



    return 0;

}
