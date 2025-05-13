#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

/*
    purpose: To create book store that show all books, add a new book (Title, Author, Date), delete a book by title, sort books by title, Author, Date (both orders), serach by title, Author and find newes and oldest 
*/
using namespace std;

    struct bookStructure {
        string title;
        string author;
        int date_of_publication;
    };

//file function
void saveBooksToFile(const vector<bookStructure>& books) {
    ofstream file("sampleBooks.txt");
    for (const auto& book : books) {
        file << book.title << "|" << book.author << "|" << book.date_of_publication << endl;
    }
    file.close();
}
    void loadBooksFromFile(vector<bookStructure>& books) {
    ifstream file("sampleBooks.txt");
    if (!file.is_open()) {
        cout << "No existing books file found." << endl;
        return;
    }

    books.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        bookStructure book;
        getline(ss, book.title, '|');
        getline(ss, book.author, '|');
        string year;
        getline(ss, year, '|');
        try {
            book.date_of_publication = stoi(year);
            books.push_back(book);
        } catch (...) {
            cout << "Error reading book data.." << endl;
        }
    }
    file.close();
}
void sortByTitle(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].title > key.title) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

void sortByAuthor(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].author > key.author) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

void sortByDateAsc(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].date_of_publication > key.date_of_publication) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

void sortByDateDesc(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].date_of_publication < key.date_of_publication) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

int linearSearchByTitle(const vector<bookStructure>& books, const string& title) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].title == title) {
            return i;
        }
    }
    return -1;
}

int linearSearchByAuthor(const vector<bookStructure>& books, const string& author) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].author == author) {
            return i;
        }
    }
    return -1;
}

int binarySearchByTitle(const vector<bookStructure>& books, const string& title) {
    size_t left = 0;
    size_t right = books.size() - 1;
    
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        
        if (books[mid].title == title) {
            return mid;
        }
        
        if (books[mid].title < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<bookStructure> books;
    loadBooksFromFile(books);
    int choice;
    bool run = true;

    while (run) {
        // Clear screen before showing menu
        system("cls");  // for Windows
       
        cout << "\n=== Welcome to BookStore System ===" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. Insert a New Book" << endl;
        cout << "3. Delete a Book (by Title)" << endl;
        cout << "4. Sort Books" << endl;
        cout << "5. Search Books" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice (1-6): ";
        
        // Better input handling
        string input;
        getline(cin, input);
        
        // Convert string to int safely
        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid input! Please enter a number between 1 and 6." << endl;
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
                        cout << "Publication Year: " << book.date_of_publication << endl;
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
                    newBook.date_of_publication = stoi(year);
                    books.push_back(newBook);
                    saveBooksToFile(books);
                    cout << "Book added successfully!" << endl;
                } catch (...) {
                    cout << "Invalid year! Book not added." << endl;
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
                    for (auto it = books.begin(); it != books.end(); ++it) {
                        if (it->title == titleToDelete) {
                            books.erase(it);
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

                cout << "\nChoose sorting option:" << endl;
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
                        cout << "Books sorted by title!" << endl;
                        break;
                    case 'b':
                    case 'B':
                        sortByAuthor(books);
                        cout << "Books sorted by author!" << endl;
                        break;
                    case 'c':
                    case 'C':
                        sortByDateAsc(books);
                        cout << "Books sorted by date (oldest to newest)!" << endl;
                        break;
                    case 'd':
                    case 'D':
                        sortByDateDesc(books);
                        cout << "Books sorted by date (newest to oldest)!" << endl;
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
                    cout << "Publication Year: " << book.date_of_publication << endl;
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
                        cout << "\nBook found:" << endl;
                        cout << "Title: " << books[index].title << endl;
                        cout << "Author: " << books[index].author << endl;
                        cout << "Publication Year: " << books[index].date_of_publication << endl;
                    } else {
                        cout << "Book not found!" << endl;
                    }
                } else if (searchChoice == "b") {
                    cout << "Enter author to search: ";
                    string searchAuthor;
                    getline(cin, searchAuthor);
                    
                    int index = linearSearchByAuthor(books, searchAuthor);
                    
                    if (index != -1) {
                        cout << "\nBook found:" << endl;
                        cout << "Title: " << books[index].title << endl;
                        cout << "Author: " << books[index].author << endl;
                        cout << "Publication Year: " << books[index].date_of_publication << endl;
                    } else {
                        cout << "Book not found!" << endl;
                    }
                } else if (searchChoice == "c") {
                    if (books.empty()) {
                        cout << "No books available!" << endl;
                    } else {
                        sortByDateDesc(books);
                        cout << "\nNewest Book:" << endl;
                        cout << "Title: " << books[0].title << endl;
                        cout << "Author: " << books[0].author << endl;
                        cout << "Publication Year: " << books[0].date_of_publication << endl;
                    }
                } else if (searchChoice == "d") {
                    if (books.empty()) {
                        cout << "No books available!" << endl;
                    } else {
                        sortByDateAsc(books);
                        cout << "\nOldest Book:" << endl;
                        cout << "Title: " << books[0].title << endl;
                        cout << "Author: " << books[0].author << endl;
                        cout << "Publication Year: " << books[0].date_of_publication << endl;
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