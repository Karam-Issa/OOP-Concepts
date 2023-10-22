#pragma once

#include <iostream>
#include <string>
using namespace std;

class Book // Book class definition
{
private:
	string bookTitle;
	//a book ISBN can be any string (such as 978-3-16) and it should be unique for each book.
	string bookISBN;//International Standard Book Number.
	string bookFirstAuther;
	int numberOfCopies;

public:
	// A parameterized constructor with default arguments.
	Book(string title = "-", string isbn = "-", string firstAuther = "-", int copies = 0);

	//copy constructor
	Book(const Book& bk);
	//Setters.
	void setBookTitle(string title);
	void setISBN(string isbn);
	void setFirstAuther(string firstAuther);
	void setNumberOfCopies(int num);

	//Getters.
	string getBookTitle() const;
	string getBookISBN() const;
	string getBookFirstAuther() const;
	int getNumberOfCopies() const;

	// A function that update the number of copies in a book.
	void updateBoolNumCopies(int n);

	//a function that prints the information for a unique book
	void printBook() const;


};

