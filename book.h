#ifndef BOOK_H
#define BOOK_H

/*
    purpose: To create book store that show all books, add a new book (Title, Author, Date), delete a book by title, sort books by title, Author, Date (both orders), serach by title, Author and find newes and oldest 
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
    int date_of_publication;
};

// Function declarations
void saveBooksToFile(const vector<bookStructure>& books);
void loadBooksFromFile(vector<bookStructure>& books);

void sortByTitle(vector<bookStructure>& books);
void sortByAuthor(vector<bookStructure>& books);
void sortByDateAsc(vector<bookStructure>& books);
void sortByDateDesc(vector<bookStructure>& books);

int linearSearchByTitle(const vector<bookStructure>& books, const string& title);
int linearSearchByAuthor(const vector<bookStructure>& books, const string& author);
int binarySearchByTitle(const vector<bookStructure>& books, const string& title);

#endif