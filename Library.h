#pragma once
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;


//Library class definition
class Library {
private:
	//represents the maximum number of books (i.e., unique book titles) that can be added to the library.N
	int maxSize;
	//tracks the current number of unique book titles in the library
	int current;
	//a pointer to a dynamic array of Books that represent all unique book titles in the library
	Book* bookList;


	//This private member function  resizes the dynamic array pointed to by the pointer bookList.
	void resizeLibrary(int n);
public:
	//parameterized constructor
	Library(int n);

	//Copy Constructor
	Library(const Library& x);

	//destructor
	~Library();

	//a boolean function that returns true if the library is empty. and false otherwise
	bool isEmpty();

	// a boolean function that returns true if the library is full, and false otherwise
	bool isFull();

	//returns the index of the book with requested title if found in the library, otherwise returns - 1.
	int findBookByTitle(const string& title);

	// returns the index of the book with an ISBN that is equal to isbn if found in bookList, otherwise returns - 1.
	int findBookByISBN(const string& isbn);


	/*
1- adds the book to the end of list bookList if the Library is not full and the
book does not already exist in the list

2-If the book to is already in the list, then update the number of copies of that
book (increment the current number of copies by the amount number_of_copies)

3-If a book is not in the list, but the list is full, then resize the library pointed. by
bookList to allow for 10 more books then add the book at the first available location
(i.e., after all the books that already exist)
*/
	void addBook(const Book& book);

	//this function is similar to the previous method but this one asks for all required book data to be input by the user of your program.
	void addBook();//function overiding

	//Getters
	int getMaxSize() const;
	int getCurrent() const;

	//calculates the percentage of the maximum number of books filled with books.
	float capacityUsage();


	bool removeBookCopy(const string& isbn);

	//friend function that receives a Library object and prints the information of all the books in that library
	friend void printLibrary(const Library& libr);

	//function to print the current size fo the library
	void printCurrentSizeOfLibrary() const;

};