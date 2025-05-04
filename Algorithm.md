//Step by Step Algorithm of the code conatin Feature, pseudocode, Menu dispaly, Simple Flow chart
# Features 

Feature	                Action
View Books	            Show all books
Insert Book	            Add a new book (Title, Author, Date)
Delete Book             Delete a book by Title
Sort Books	            By Title, Author, Date (both orders)
Search Books      	    By Title, Author, Find Newest, Find Oldest
Exit	                End the program
  
       -//-
# Pseudocode 

Start

Create a structure Book with:
    - title
    - author
    - dateOfPublication

Create a list/array/vector of books

repeat:
    Display Menu:
        1. View All Books
        2. Insert a New Book
        3. Delete a Book (by Title)
        4. Sort Books
            a. By Title (A-Z)
            b. By Author (A-Z)
            c. By Date (Oldest to Newest)
            d. By Date (Newest to Oldest)
        5. Search Books
            a. By Title
            b. By Author
            c. Find Newest Book
            d. Find Oldest Book
        6. Exit Program

    Get user's choice

    if choice is View Books:
        For each book in the list:
            Display title, author, dateOfPublication

    if choice is Insert a New Book:
        Input title, author, dateOfPublication
        Add book to list

    if choice is Delete a Book:
        Input title to delete
        Search for the book by title
        If found:
            Remove the book from the list
        Else:
            Display "Book not found"

    if choice is Sort Books:
        Ask how to sort
        Perform selection sort:
            - Alphabetically (for title/author)
            - By date ascending or descending

    if choice is Search Books:
        Ask how to search:
            - By title/author (binary search after sorting)
            - Find newest/oldest (simple scan)

    if choice is Exit:
        Display "Goodbye!" and stop the program

until choice is Exit

End
     -//-

# Menu Display Example

========================================
        Welcome to BookStore System
========================================

1. View All Books
2. Insert a New Book
3. Delete a Book
4. Sort Books
   a. By Title (A-Z)
   b. By Author (A-Z)
   c. By Date (Oldest to Newest)
   d. By Date (Newest to Oldest)
5. Search Books
   a. By Title
   b. By Author
   c. Find Newest Book
   d. Find Oldest Book
6. Exit Program

Enter your choice: 
         -//-

# Simple Flowchart
+-----------------+
|     Start       |
+-----------------+
        |
        v
+-----------------+
|  Display Menu   |
+-----------------+
        |
        v
+----------------------------------------+
| 1. View Books                         |
| 2. Insert New Book                    |
| 3. Delete Book                        |
| 4. Sort Books (Title/Author/Date)      |
| 5. Search Books (Title/Author/Newest)  |
| 6. Exit                               |
+----------------------------------------+
        |
        v
+---------------------------+
| Perform selected action   |
+---------------------------+
        |
        v
+-----------------+
| Display Menu    |
+-----------------+
(Repeat)
If Exit is chosen:
+-----------------+
|     Exit        |
+-----------------+
