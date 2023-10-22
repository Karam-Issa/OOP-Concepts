#include <iostream>
#include <string>
#include <cassert>
//#include <iomanip>
#include <string.h>
#include "Book.h"
#include "Library.h"
using namespace std;

void Library::resizeLibrary(int n) {

	//The function should validate that n is a positive integer
	//The function should increase the array capacity by the amount of n.
	if (n > 0) {
		maxSize += n;
		Book* temp = new Book[maxSize];
		//copying elements from old array to new array, The function must preserve the data that was already in the list.

		for (int i = 0; i < this->current; i++) {
			temp[i] = this->bookList[i];
		}
		//delete and free up memory of the old array
		delete[] bookList;
		//make the bookList pointer point to the newly resized array
		this->bookList = temp;


	}

}


//parameterized constructor for Library Object
Library::Library(int n) {
	//sets maxSize to n
	this->maxSize = n;
	//allocates dynamic space of size maxSize, and makes the bookList pointer points to the allocated space
	this->bookList = new Book[maxSize];
	// ensure memory allocated
	//assert(bookList != 0);
	// sets current number of unique books to 0.
	this->current = 0;
}

//copy constructor
Library::Library(const Library& x) {
	//normal copy
	this->maxSize = x.maxSize;
	this->current = x.current;
	//implementation of Deep copy by allocating a new memory location and making the bookList pointer point to it
	this->bookList = new Book[this->maxSize];
	// ensure memory allocated
	//assert(bookList != 0);
	//copy every book object using memory copy from Library object sent by reference as parameter(By fax) to the recieving newly constructed object
	//optimized by only coping non-empty elements of the array.
	//if error occurs change this->current to maxSize
	for (int i = 0; i < this->current; i++) {
		this->bookList[i] = x.bookList[i];
	}

}


//Deallocates any dynamically allocated memory for an object
Library::~Library() {
	delete [] bookList;
}


// checks if library is empty by checking  current number of unique books
bool Library::isEmpty() {
	// checks if library is empty by checking  current number of unique books
	
		return (current == 0);
	
	//return ((this->bookList[0].getBookFirstAuther() == "-") && (this->bookList[0].getBookTitle() == "-") && (this->bookList[0].getBookISBN() == "-") && (this->bookList[0].getNumberOfCopies() == 0));
}



//// checks if library is full by checking  current number of unique books
bool Library::isFull() {
	return (current == maxSize);
	//return !((this->bookList[maxSize-1].getBookFirstAuther() == "-") && (this->bookList[maxSize - 1].getBookTitle() == "-") && (this->bookList[maxSize - 1].getBookISBN() == "-") && (this->bookList[maxSize - 1].getNumberOfCopies() == 0));
}




int Library::findBookByTitle(const string& title) {

	//if the library array is empty no need to loop through and find book Title
	if (isEmpty()) {
		return -1;
	}else {
		int i = 0;
		//exit loop when you reach the end of the array or when the index of the book with requested title if found in the library
		while (i <this->current) {
			if ((this->bookList[i].getBookTitle() == title)) {
				//returning the index of the book with requested title
				return i;
				break;
			}
			i++;
		}
		return -1;
	}
}

int Library::findBookByISBN(const string& isbn) {
	//if the library array is empty no need to loop through and find book ISBN
	if (isEmpty()) {
		return -1;
	}
	else {
		int i = 0;
		//exit loop when you reach the end of the array or when the index of the book with requested ISBN if found in the library
		while (i < this->maxSize) {
			if ((this->bookList[i].getBookISBN() == isbn)) {
				//returning the index of the book with requested ISBN
				return i;
				break;
			}
			i++;
		}
		return -1;
	}
}



void Library::addBook(const Book& book) {
	//adds the book to the end of list bookList if the Library is not full and the book does not already exist in the list
	//if not full
	if (!(isFull())) {
		//check if the book does not already exist in the list using th ISBN as it should be unique for each book
		if (findBookByISBN(book.getBookISBN()) == -1) {
			
			//add the book to the end of list bookList
			bookList[this->current] = book;
			
			this->current++;
		}
		else {
			////the book to is already in the list,
			int index = findBookByISBN(book.getBookISBN());
			// then update the number of copies of that book(increment the current number of copies by the amount number_of_copies)
			this->bookList[index].setNumberOfCopies(this->bookList[index].getNumberOfCopies() + book.getNumberOfCopies());
		}
	}
	else  {// but the list is full,

		//If a book is not in the list
		if (findBookByISBN(book.getBookISBN()) == -1) {
			resizeLibrary(10);
			//add the book to the end of list bookList
			bookList[this->current] = book;
			this->current++;
		}
	}
}
//
void Library::addBook() {
	cout << "Please enter the required Information for the following Book:" << endl;
	string usrBookIsbn, usrBookTitle, usrFirstAuther;
	int usrNumOfCopies;
	
		
		cout << "Book #" << this->current +1<< endl;
		cout << "Book ISBN (International Standard Book Number): ";
		cin >> usrBookIsbn;
		cout << "Book Title: ";
		cin >> usrBookTitle;
		cout << "Book Fisrt Auther: ";
		cin >> usrFirstAuther;
		cout << "Number of Copies: ";
		cin >> usrNumOfCopies;
		Book UsrInputtedBook(usrBookTitle, usrBookIsbn, usrFirstAuther, usrNumOfCopies);
		//adds the book using the function addBook written before
		addBook(UsrInputtedBook);

	}

//max size getter
int Library::getMaxSize() const {
	return this->maxSize;
}
//current setter
int Library::getCurrent() const {
	return this->current;
}


float Library::capacityUsage() {
	
	//use of #include <iomanip> to return the float percentage 2 decimal places, if not it might return a double
	return ((current * 1.0 / maxSize) * 100);
	
}



bool Library::removeBookCopy(const string& isbn){
	//if the book exists in the library 
	if (findBookByISBN(isbn) != -1) {
		//n decrements the number of copies of the book by one
		this->bookList[findBookByISBN(isbn)].updateBoolNumCopies(bookList[findBookByISBN(isbn)].getNumberOfCopies() - 1);

		//If the number of copies becomes zero,
		if (this->bookList[findBookByISBN(isbn)].getNumberOfCopies() == 0) {
			for (int i = findBookByISBN(isbn); i < this->maxSize-1; i++) {
				//shift left the books starting from the index of the deleted book by overwriting its information
				this->bookList[i] = this->bookList[i + 1];
			}
			//all to the right of the deleted book will shift left and we will have two duplicate books at the end of the list 
			//we have to unset ALL the values of the last book in the list so there are always unique books and the deleted book has freed up space in the list
			this->bookList[maxSize - 1].setBookTitle("-");
			this->bookList[maxSize - 1].setFirstAuther("-");
			this->bookList[maxSize - 1].setISBN("-");
			this->bookList[maxSize - 1].setNumberOfCopies(0);
			//no we have returned the duplicated book at the end of the list as an "empty book" asn has freed up space in the list
			current--; //update current book count
			
		}

		return true;
	}
	else {
		cout << "The book ISBN entered was not found and hence no book's number of copies was modified(removed)" << endl;
		return false;
	}
}

void printLibrary(const Library& libr){
	for (int i = 0; i < libr.getMaxSize(); i++) {
		cout << "\n\nBook #" << i + 1 << endl;
		libr.bookList[i].printBook();
	}
	//cout << "Stop Printing"<<endl;
}

void Library::printCurrentSizeOfLibrary() const {
	cout << "The CURRENT size of the library is: " << getCurrent() << endl;
}