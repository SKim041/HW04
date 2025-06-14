﻿#include "HW04.h"
#include <iostream>

//Book Public
const void Book::displayBook() {
	cout << "제목: " << this->title << " 작가: " << this->author;
}

// BookManager Private
Book* BookManager::searchByTitle(const string& title) {
	Book* result = nullptr;
	for (auto& item : this->books) {
		if (item.title == title) {
			result = &item;
			return result;
		}
	}
	return result;
}
vector<Book*> BookManager::searchByAuthor(const string& author) {
	vector<Book*> listBooks;
	for (auto &item : this->books) {
		if (item.author == author) {
			listBooks.push_back(&item);
		}
	}
	return listBooks;
}
// BookManager Public
void BookManager::addBook(const string& title, const string& author) {
	this->books.push_back(Book(title, author));
}
void BookManager::displayAllBooks() {
	cout << endl << "---------------책 목록---------------" << endl;
	for (auto &item : this->books) {
		item.displayBook();
		cout << endl;
	}
}

Book* BookManager::getByTitle(const string& title) {
	if (this->searchByTitle(title) == nullptr) {
		cout << "제목: " << title << " 책을 찾을 수 없습니다." << endl;
	}
	return this->searchByTitle(title);	
}
vector<Book*> BookManager::getByAuthor(const string& author) {
	if (this->searchByAuthor(author).size() == 0) {
		cout << "작가: " << author << " 의 책을 찾을 수 없습니다." << endl;
	}
	return this->searchByAuthor(author);
}
// BorrowManager Public
void BorrowManager::displayStockByTitle(const string& title) {
	Book* item = bookManager.getByTitle(title);
	if (item != nullptr) {
		item->displayBook();
		cout << " 재고: " << stock[item] << endl;
	}
}
void BorrowManager::displayStockByAuthor(const string& author) {
	vector<Book*> items = bookManager.getByAuthor(author);
	for (auto b : items) {
		b->displayBook();
		cout << " 재고: " << stock[b] << endl;
	}
}
void BorrowManager::displayAllStock() {
	cout << endl << "---------------책 재고 목록---------------" << endl;
	for (auto &item : this->stock) {
		item.first->displayBook();
		cout<< " 재고: " << item.second << endl;
	}
}
void BorrowManager::initializeStock(Book* book, int quantity) {
	if (book == nullptr) {
		cout << "*******initializeStock Error*******" << endl;
	}
	else {
		this->stock[book] = quantity;
	}
}
void BorrowManager::borrowBookByTitle(const string& title) {
	Book* temp = this->bookManager.getByTitle(title);
	cout << endl << "---------------책 대여---------------" << endl;
	temp->displayBook();
	if (this->stock[temp] == 0) {
		cout << " 재고 부족. 대여 불가능" << endl;
	}
	else {
		cout << " 대여 완료" << endl;
		this->stock[temp]--;
	}
}
void BorrowManager::returnBook(const string& title) {
	Book* temp = this->bookManager.getByTitle(title);
	cout << endl << "---------------책 반납---------------" << endl;
	temp->displayBook();
	if (this->stock[temp] == max_quantity) {
		cout << " 반납 오류: 최대 재고" << endl;
	}
	else {
		cout << " 반납 완료" << endl;
		this->stock[temp]++;
	}
	
}
