#ifndef BOOK_H
#define BOOK_H

/*
    purpose: To create book store system that shows all books, add a new book (Title, Author, Date), delete a book by title, sort books by title, Author, Date (both orders), search by title, Author and find newest and oldest book. 
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct bookStructure {
    string title;
    string author;
    int year_of_publication;
};

// Function declarations
void saveBooksToFile(const vector<bookStructure>& books); //Writes all books to a file
void loadBooksFromFile(vector<bookStructure>& books); //Reads books from file into vector

//Sorting Functions using Insertion Sort
void sortByTitle(vector<bookStructure>& books);
void sortByAuthor(vector<bookStructure>& books);
void sortByYearAsc(vector<bookStructure>& books);
void sortByYearDesc(vector<bookStructure>& books);
//Searching Functions using Linear Search and binary search 
int linearSearchByTitle(const  vector<bookStructure>& books, const string& title); //Checks each book one by one
int linearSearchByAuthor(const vector<bookStructure>& books, const string& author);
int binarySearchByTitle(const vector<bookStructure>& books, const string& title); //Performs binary search for sorted vector

//Description of Standard library functions their roles and time complexity
/*
1. #include <vector>
   Role: Used to store a list of bookStructure objects (books)
2. #include <fstream>
    Role: file handling
        ofstream file("sampleBooks.txt") - Used to write data to a file || O(1)
        ifstream file("sampleBooks.txt") -  Used to read data from a file || O(1)
3. #include <string>, #include <sstream>
    Role: string manipulation
        getline(ss, book.title, '|') - Reads from a stringstream up to the delimiter || O(k) k= number of characters read
        stoi(year)- Convert string to int
          || O(log n)
*/
/*
    Vector based functions 
    book.push_back() = adds book to end
    books.clear() = remove all books and frees memory
    book[i] or books[j] - access by index
*/
#endif