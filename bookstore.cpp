#include "book.h"

void saveBooksToFile(const vector<bookStructure>& books) {
    ofstream file("sampleBooks.txt");  // Creates an output file stream (ofstream) named file. Opens a file called "sampleBooks.txt" in write mode
    for (const auto& book : books) {
        file << book.title << "|" << book.author << "|" << book.year_of_publication << endl;
    }
}
void loadBooksFromFile(vector<bookStructure>& books) {
    ifstream file("sampleBooks.txt");    //Opens the file "sampleBooks.txt" for reading using an input file stream (ifstream).
    if (!file.is_open()) {
        cout << "No existing books file found." << endl;
        return;
    }

    books.clear();
    string line;
    while (getline(file, line)) { //Reads the file line by line until the end
        stringstream ss(line); //Converts the line into a string stream so that you can easily split it using the '|' delimiter.
        bookStructure book; //Creates a temporary bookStructure object to store the current book's info.
        getline(ss, book.title, '|'); //Reads title and author from the stream up to the '|' delimiter and stores them.
        getline(ss, book.author, '|');
        string year;
        getline(ss, year, '|');
        try {
            book.year_of_publication = stoi(year);//Converts string to integer ("2020" → 2020)
            books.push_back(book);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid year format:it is not a number" << endl;
        }
        catch (const std::out_of_range& e) {
            cout << "Invalid year format: number too large" << endl;
        }
    }
    file.close();
}
void sortByTitle(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j;
        for (j = i - 1; j >= 0 && books[j].title > key.title; j--) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

void sortByAuthor(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j; 
        for (j = i - 1; j >= 0 && books[j].author > key.author;j-- ) {
            books[j + 1] = books[j];
       }
        books[j + 1] = key;
    }
}

void sortByYearAsc(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j;
        for(j = i - 1; j >= 0 && books[j].year_of_publication > key.year_of_publication; j--) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

void sortByYearDesc(vector<bookStructure>& books) {
    for (size_t i = 1; i < books.size(); i++) {
        bookStructure key = books[i];
        int j;
         for(j = i - 1; j >= 0 && books[j].year_of_publication < key.year_of_publication; j--) {
            books[j + 1] = books[j];
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