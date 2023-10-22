# OOP-Concepts
## 1.Classes and Objects:

Classes are used to define blueprints for objects.
Example: Book and Library classes define the blueprint for book objects and library objects.

## 2.Encapsulation:

The data members of classes are private, and access to them is controlled through public member functions (getters and setters).
Example: Private data members in the Book and Library classes are encapsulated, and access is managed through public member functions like 'getBookTitle()', 'setBookTitle()', etc.

## 3.Constructor and Destructor:

Constructors are used to initialize objects, and destructors are used to release resources when an object is destroyed.
Example: Constructor and destructor in the Book and Library classes.






## 4.Abstraction
Abstraction hides the complex implementation details and exposes only the necessary features.
Example: The Library class abstracts the details of book management, allowing the user to interact with it through high-level functions like addBook().

## 5.Friend Functions:

Friend functions can access private and protected members of a class.
Example: The 'printLibrary' function is a friend function that can access and print the private data members of the Library class.
Overloading:

## 6.Overloading allows multiple functions with the same name but different parameter lists to coexist.
Example: The 'addBook()' function is overloaded, with one version accepting a Book object and the other accepting user input to create a book object.
Data Hiding:

## 7.Private data members are hidden from external access, preventing unauthorized modifications.
Example: Private data members like bookTitle, bookISBN, and numberOfCopies are not directly accessible from outside the class.


## 8.Dynamic Memory Allocation:

Dynamic memory allocation is used for creating and resizing arrays of objects.
Example: The new operator is used to create dynamic arrays for books in the Library class.

## 9.Member Functions:

Member functions encapsulate behavior associated with objects.
Example: Functions like addBook(), findBookByTitle(), and printLibrary are member functions that operate on book and library objects.

## 10.Constructor Overloading:
Constructor overloading allows the creation of objects with different sets of parameters.
Example: The Book constructor is overloaded to create objects with different sets of initial data.

## 11.Deep Copy and Copy Constructor:

A copy constructor creates a new object as a copy of an existing object. Deep copy ensures that the copied object is independent of the original object.
Example: The Book copy constructor in the Book class creates a deep copy of a book object.
