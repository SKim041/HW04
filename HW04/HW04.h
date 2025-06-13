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
	Book* searchByTitle(const string& title);
	vector<Book*> searchByAuthor(const string& author);

public:
	BookManager() {}

	void addBook(const string& title, const  string& author);
	void displayAllBooks();
	Book* getByTitle(const string& title);
	vector<Book*> getByAuthor(const string& author);

};

class BorrowManager {
private:
	BookManager& bookManager;
	unordered_map<Book*, int> stock;
	static const int max_quantity = 3;
public:
	BorrowManager(BookManager& bm) :bookManager(bm) {}
	void initializeStock(Book* book, int quantity = max_quantity);
	void borrowBookByTitle(const string& title);
	void returnBook(const string& title);
	void displayAllStock();
	void displayStockByTitle(const string& title);
	void displayStockByAuthor(const string& author);
};


#endif
