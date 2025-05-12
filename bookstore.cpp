/*
    purpose: To create book store that show all books, add a new book (Title, Author, Date), delete a book by title, sort books by title, Author, Date (both orders), serach by title, Author and find newes and oldest 
*/

#include <iostream>
#include <string>
using namespace std;

struct bookStructure {
    string title;
    string author;
    int date_of_publication;
};

int main() {
    // array list 

    cout << "Welcome to BookStore System" << endl;
    cout << "1. View All Books" << endl;
    cout << "2. Insert a New Book" << endl;
    cout << "3. Delete a Book (by Title)" << endl;
    cout << "4. Sort Books" << endl;
    cout << "   a. By Title (A-Z)" << endl;
    cout << "   b. By Author (A-Z)" << endl;
    cout << "   c. By Date (Oldest to Newest)" << endl;
    cout << "   d. By Date (Newest to Oldest)" << endl;
    cout << "5. Search Books" << endl;
    cout << "   a. By Title" << endl;
    cout << "   b. By Author" << endl;
    cout << "   c. Find Newest Book" << endl;
    cout << "   d. Find Oldest Book" << endl;
    cout << "Exit program" << endl;
    
    int choice;
    cin >> choice;

    switch(choice){
        case 1: 
            // code for viewing books
            break;
        case 2:
            // code for inserting a book
            break;
        case 3: 
            // code for deleting a book
            break;
        case 4:
            // code for sorting books
            break;
        case 5: 
            // code for searching books
            break;
        case 6: 
            // code for exiting
            break;
        default: 
            // code for invalid choice
            break;
    }
    return 0;
}