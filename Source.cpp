
#include<iostream>
#include<string>
#include "Book.h"
#include "Library.h"

using namespace std;



int main() {
	//1 Create a dynamic array of Book objects named myBooks_items of size 5
	Book* myBooks_items = new Book[5];
	//create temp var to fil myBooks_items
	string tempTitle, tempISBN, tempFirstAuthor;
	int tempNumOfCopies;
	//
	for (int i = 0; i < 5; i++) {
				cout << "\nplease fill information about book " << i + 1 << endl;
				cout << "ISBN(International Standard Book Number): ";
				cin >> tempISBN;
				cout << "Title: ";
				cin >> tempTitle;
				cout << "First author: ";
				cin >> tempFirstAuthor;
				cout << "Number of copies: ";
				cin >> tempNumOfCopies;
				cout << "\n";
				//2.Fill myBooks_items with proper data from the user for 5 different books.
				myBooks_items[i] = Book(tempTitle, tempISBN, tempFirstAuthor, tempNumOfCopies);
	}
	//3.Create a Library object named lib with a maxSize of 6

	Library lib(6);
	
	//4.Fill the first 5 items of the library lib using the boosk items from myBooks_items array
	for (int i = 0; i < 5; i++) {
		lib.addBook(myBooks_items[i]);
	}

	//5.Create a dynamic object of type Book using the data of the second object in the array myBooks_items, second object so position [1]
	tempTitle = myBooks_items[1].getBookTitle();
	tempISBN = myBooks_items[1].getBookISBN();
	tempFirstAuthor= myBooks_items[1].getBookFirstAuther();
	tempNumOfCopies = myBooks_items[1].getNumberOfCopies();
	Book book2(tempTitle, tempISBN, tempFirstAuthor, tempNumOfCopies);

	//6.Delete the dynamic array pointed to by myBooks_items
	delete[] myBooks_items;

	//7.Add 3 more copies of the book from Question2-point 5
	for (int i = 0; i < 3; i++) {
		lib.addBook(book2);
	}


	//8.Add two more unique books by calling addBook()
	for (int i = 0; i < 2; i++) {
		lib.addBook();
	}


	//9.display the details of all books in lib
	printLibrary(lib);

	//10/call a proper function to print the current size of the library
	lib.printCurrentSizeOfLibrary();
	
	//11.Print the usage-percentage of the bookList in lib using a proper function call.
	cout << "The usage-percentage of the booklist in lib is: " << lib.capacityUsage() << "%" << endl;

	//12. remove all copies of the book from Question2-point 5.
	int totalNumberOfCopies = book2.getNumberOfCopies() + 3;
	for (int i = 0; i < totalNumberOfCopies; i++) {
		//remove all copies by removing 1 book every loop, and loop for the total number of copies for the book
		lib.removeBookCopy(book2.getBookISBN());
	}
	//13.Once again, Display the details of all the books in lib.
	printLibrary(lib);
	system("pause");
	

}

