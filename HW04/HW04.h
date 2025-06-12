#pragma once
#ifndef HW04_H
#define	HW04_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Book {
public:
	string title;
	string author;

	Book(string t, string a) :title(t), author(a) {}
	const void displayBook();
};

class BookManager {
private:
	vector<Book> books;
	Book* searchByTitle(string title);
	vector<Book*> searchByAuthor(string author);

public:
	BookManager() {}

	void addBook(string title, string author);
	void displayAllBooks();
	Book* getByTitle(string title);
	vector<Book*> getByAuthor(string author);

};

class BorrowManager {
private:
	BookManager& bookManager;
	unordered_map<Book*, int> stock;
	static const int max_quantity = 3;
public:
	BorrowManager(BookManager& bm) :bookManager(bm) {}
	void initializeStock(Book* book, int quantity = max_quantity);
	void borrowBookByTitle(string title);
	void returnBook(string title);
	void displayStock();
};


#endif
