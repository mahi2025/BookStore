#include "book.h"

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
        cout << "No existing books file found. Starting with empty bookstore." << endl;
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
            cout << "Error reading book data. Skipping invalid entry." << endl;
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