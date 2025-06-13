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

    while (true) {

        system("cls");
        cout << "******BOOK MANAGER******" << endl;
        cout << "1. 책 목록 및 재고 확인" << endl;
        cout << "2. 책 추가하기" << endl;
        cout << "3. 제목으로 책 찾기" << endl;
        cout << "4. 작가로 책 찾기" << endl;
        cout << "5. 책 대여하기" << endl;
        cout << "6. 책 반납하기" << endl;
        cout << "7. 종료" << endl;
        cout << "원하는 항목의 번호를 입력하세요: ";
        int inputNum;
        cin >> inputNum;
        cin.ignore();
        if (inputNum == 1) {
            borrow_m.displayAllStock();
        }
        else if (inputNum == 2) {
            string title, author;
            cout << "제목: ";
            getline(cin, title);
            cout << "작가: ";
            getline(cin, author);
            book_m.addBook(title, author);
            borrow_m.initializeStock(book_m.getByTitle(title));
        }
        else if (inputNum == 3) {
            string title;
            cout << "제목: ";
            getline(cin, title);
            //get 못하면 display 에러남
            borrow_m.displayStockByTitle(title);            
        }
        else if (inputNum == 4) {
            string author;
            cout << "작가: ";
            getline(cin, author);
            borrow_m.displayStockByAuthor(author);
        }
        else if (inputNum == 5) {
            string title;
            cout << "대여할 책의 제목: ";
            getline(cin, title);
            borrow_m.borrowBookByTitle(title);
        }
        else if (inputNum == 6) {
            string title;
            cout << "반납할 책의 제목: ";
            getline(cin, title);
            borrow_m.returnBook(title);
        }
        else if (inputNum == 7) {
            cout<<"종료" << endl;
            break;
        }
        else {
            cout << "유효하지 않은 번호입니다." << endl;
        }

    
        // press any key to continue...
        system("pause");
    
    }

    return 0;

}
