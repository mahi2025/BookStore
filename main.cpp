#include "book.h"
#include <cstdlib>

int main() {
    vector<bookStructure> books;
    loadBooksFromFile(books);
    int choice;
    bool run = true;

    while (run) {
        // Clear screen before showing menu
        system("cls");  
       
        cout << "\n=== Welcome to BookStore System ===" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. Insert a New Book" << endl;
        cout << "3. Delete a Book (by Title)" << endl;
        cout << "4. Sort Books" << endl;
        cout << "5. Search Books" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice (1-6): ";
        
        string input;
        getline(cin, input);
        
        // Convert string to int safely
        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid input! Please enter a number between (1-6)." << endl;
            cout << "Press Enter to continue...";
            cin.get();
            continue;
        }

        switch(choice) {
            case 1: 
                if (books.empty()) {
                    cout << "No books available in the store." << endl;
                } else {
                    cout << "\nAll Books in Store:" << endl;
                    cout << "-----------------" << endl;
                    for (const auto& book : books) {
                        cout << "Title: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Publication Year: " << book.year_of_publication << endl;
                        cout << "-----------------" << endl;
                    }
                }
                cout << "\nPress Enter to continue...";
                cin.get();
                break;

            case 2: {
                bookStructure newBook;
                cout << "\nEnter Book Details:" << endl;
                cout << "Title: ";
                getline(cin, newBook.title);
                cout << "Author: ";
                getline(cin, newBook.author);
                cout << "Publication Year: ";
                string year;
                getline(cin, year);
                try {
                    newBook.year_of_publication = stoi(year);
                    books.push_back(newBook);
                    saveBooksToFile(books);
                    cout << "Book added successfully!" << endl;
                } catch (...) {
                    cout << "You didn't add any book" << endl;
                }
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }

            case 3: {
               if (books.empty()) {
                cout << "No books available to delete!" << endl;
            } else {
                string titleToDelete;
                cout << "Enter the title of the book to delete: ";
                getline(cin, titleToDelete);
            
                bool found = false;
            
                for (size_t i = 0; i < books.size(); ++i) {
                    if (books[i].title == titleToDelete) {
                        books.erase(books.begin() + i);
                        saveBooksToFile(books); 
                        found = true;
                        cout << "Book deleted successfully!" << endl;
                        break;
                    }
                }
            
                if (!found) {
                    cout << "Book not found!" << endl;
                }
            }
            
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }

            case 4: {
                if (books.empty()) {
                    cout << "No books available to sort!" << endl;
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                }
                cout << "\nChoose sorting option: " << endl;
                cout << "a. By Title (A-Z)" << endl;
                cout << "b. By Author (A-Z)" << endl;
                cout << "c. By Date (Oldest to Newest)" << endl;
                cout << "d. By Date (Newest to Oldest)" << endl;
                cout << "Enter your choice (a-d): ";
                
                char sortChoice;
                cin >> sortChoice;
                cin.ignore();

                switch(sortChoice) {
                    case 'a':
                    case 'A':
                        sortByTitle(books);
                        break;
                    case 'b':
                    case 'B':
                        sortByAuthor(books);
                        break;
                    case 'c':
                    case 'C':
                        sortByYearAsc(books);
                        break;
                    case 'd':
                    case 'D':
                        sortByYearDesc(books);
                        break;
                    default:
                        cout << "Invalid sorting option!" << endl;
                        cout << "\nPress Enter to continue...";
                        cin.get();
                        break;
                }
                
                cout << "\nSorted Books:" << endl;
                cout << "----------------" << endl;
                for (const auto& book : books) {
                    cout << "Title: " << book.title << endl;
                    cout << "Author: " << book.author << endl;
                    cout << "Publication Year: " << book.year_of_publication << endl;
                    cout << "----------------" << endl;
                }
                
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }

            case 5: {
                cout << "\nChoose search option:" << endl;
                cout << "a. By Title" << endl;
                cout << "b. By Author" << endl;
                cout << "c. Find Newest Book" << endl;
                cout << "d. Find Oldest Book" << endl;
                cout << "Enter your choice (a-d): ";
                
                string searchChoice;
                getline(cin, searchChoice);
                
                if (searchChoice == "a") {
                    cout << "Enter title to search: ";
                    string searchTitle;
                    getline(cin, searchTitle);
                    
                    sortByTitle(books);
                    int index = binarySearchByTitle(books, searchTitle);
                    
                    if (index != -1) {
                        cout << "\nThe Book is found:" << endl;
                        cout << "Title: " << books[index].title << endl;
                        cout << "Author: " << books[index].author << endl;
                        cout << "Publication Year: " << books[index].year_of_publication << endl;
                    } else {
                        cout << "Book not found!" << endl;
                    }
                } else if (searchChoice == "b") {
                    cout << "Enter author to search: ";
                    string searchAuthor;
                    getline(cin, searchAuthor);
                    
                    int index = linearSearchByAuthor(books, searchAuthor);
                    
                    if (index != -1) {
                        cout << "\nThe Book is found:" << endl;
                        cout << "Title: " << books[index].title << endl;
                        cout << "Author: " << books[index].author << endl;
                        cout << "Publication Year: " << books[index].year_of_publication << endl;
                    } else {
                        cout << "Book not found!" << endl;
                    }
                } else if (searchChoice == "c") {
                    if (books.empty()) {
                        cout << "No books available!" << endl;
                    } else {
                        sortByYearDesc(books);
                        cout << "\nThe Newest Book:" << endl;
                        cout << "Title: " << books[0].title << endl;
                        cout << "Author: " << books[0].author << endl;
                        cout << "Publication Year: " << books[0].year_of_publication << endl;
                    }
                } else if (searchChoice == "d") {
                    if (books.empty()) {
                        cout << "No books available!" << endl;
                    } else {
                        sortByYearAsc(books);
                        cout << "\n The Oldest Book:" << endl;
                        cout << "Title: " << books[0].title << endl;
                        cout << "Author: " << books[0].author << endl;
                        cout << "Publication Year: " << books[0].year_of_publication << endl;
                    }
                } else {
                    cout << "Invalid search option!" << endl;
                }
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }

            case 6:
                cout << "Thank you for using BookStore System." << endl;
                run = false;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
                cout << "Press Enter to continue...";
                cin.get();
                break;
        }
    }
    return 0;
}