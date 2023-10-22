#include <iostream>
#include <string>
#include "Book.h"
using namespace std;



// A parameterized constructor with default arguments.
Book::Book(string title, string isbn, string firstAuther, int copies)
{
	this->bookTitle = title;
	this->bookISBN = isbn;
	this->bookFirstAuther = firstAuther;
	this->numberOfCopies = copies;
}

//copy
Book::Book(const Book& bk) {
	setBookTitle(getBookTitle());
	setISBN(bk.getBookISBN());
	setFirstAuther(bk.getBookFirstAuther());
	setNumberOfCopies(bk.getNumberOfCopies());
}

//Setters
void Book::setBookTitle(string title) {
	if (title != "")
		this->bookTitle = title;
}
void Book::setISBN(string isbn) {
	if (isbn != "")
		this->bookISBN = isbn;
}
void Book::setFirstAuther(string firstAuther) {
	if (firstAuther != "")
		this->bookFirstAuther = firstAuther;
}
void Book::setNumberOfCopies(int num) {
	if (num >= 0)
		numberOfCopies = num;
}



//getters.
string Book::getBookTitle() const{
	return bookTitle;
}
string Book::getBookISBN() const{
	return bookISBN;
}
string Book::getBookFirstAuther() const {
	return bookFirstAuther;
}
int Book::getNumberOfCopies() const {
	return numberOfCopies;
}


// A function that update the number of copies in a book.
void Book::updateBoolNumCopies(int n) {
	if (n + numberOfCopies >= 0) {
		numberOfCopies = n;
	}
	
	else {
		cout << "Error: The number of copies for the book was not updated due to an invalid integer input" << endl;
	}
		
}


void Book::printBook() const {
	
	
	cout << "Book ISBN (International Standard Book Number): " << getBookISBN() << endl;;
	
	cout << "Book Title: " << getBookTitle() << endl;
	
	cout << "Book Fisrt Auther: " << getBookFirstAuther() << endl;
	
	cout << "Number of Copies: "<< getNumberOfCopies()<< endl;
	cout << "\n";
}