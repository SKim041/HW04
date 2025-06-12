#include "HW04.h"
#include <iostream>

int main()
{
    BookManager book_m;
    book_m.addBook("책1-1", "작가1");
    book_m.addBook("책1-2", "작가1");
    book_m.addBook("책2-1", "작가2");
    book_m.displayAllBooks();

    BorrowManager borrow_m(book_m);
    
    borrow_m.initializeStock(book_m.getByTitle("책1-1"));
    borrow_m.initializeStock(book_m.getByTitle("책1-2"));
    borrow_m.initializeStock(book_m.getByTitle("책2-1"));
    borrow_m.initializeStock(book_m.getByTitle("책2-2"));

    borrow_m.displayStock();

    borrow_m.borrowBookByTitle("책1-1");
    borrow_m.borrowBookByTitle("책1-1");
    borrow_m.borrowBookByTitle("책1-1");
    borrow_m.borrowBookByTitle("책1-1");
    borrow_m.borrowBookByTitle("책1-2");

    borrow_m.displayStock();

    borrow_m.returnBook("책1-1");
    borrow_m.displayStock();



    return 0;

}
