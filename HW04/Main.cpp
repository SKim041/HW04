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

    while (true) {

        system("cls");
        cout << "******BOOK MANAGER******" << endl;
        cout << "1. å ��� �� ��� Ȯ��" << endl;
        cout << "2. å �߰��ϱ�" << endl;
        cout << "3. �������� å ã��" << endl;
        cout << "4. �۰��� å ã��" << endl;
        cout << "5. å �뿩�ϱ�" << endl;
        cout << "6. å �ݳ��ϱ�" << endl;
        cout << "7. ����" << endl;
        cout << "���ϴ� �׸��� ��ȣ�� �Է��ϼ���: ";
        int inputNum;
        cin >> inputNum;
        cin.ignore();
        if (inputNum == 1) {
            borrow_m.displayAllStock();
        }
        else if (inputNum == 2) {
            string title, author;
            cout << "����: ";
            getline(cin, title);
            cout << "�۰�: ";
            getline(cin, author);
            book_m.addBook(title, author);
            borrow_m.initializeStock(book_m.getByTitle(title));
        }
        else if (inputNum == 3) {
            string title;
            cout << "����: ";
            getline(cin, title);
            //get ���ϸ� display ������
            borrow_m.displayStockByTitle(title);            
        }
        else if (inputNum == 4) {
            string author;
            cout << "�۰�: ";
            getline(cin, author);
            borrow_m.displayStockByAuthor(author);
        }
        else if (inputNum == 5) {
            string title;
            cout << "�뿩�� å�� ����: ";
            getline(cin, title);
            borrow_m.borrowBookByTitle(title);
        }
        else if (inputNum == 6) {
            string title;
            cout << "�ݳ��� å�� ����: ";
            getline(cin, title);
            borrow_m.returnBook(title);
        }
        else if (inputNum == 7) {
            cout<<"����" << endl;
            break;
        }
        else {
            cout << "��ȿ���� ���� ��ȣ�Դϴ�." << endl;
        }

    
        // press any key to continue...
        system("pause");
    
    }

    return 0;

}
