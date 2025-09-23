#include <iostream>
#include "Book.h"
using namespace std;


int main() {
    string choice;
    string Search;
    string newName, newAuthor, newContent;

    Book book[100]; 

    while (true) {
        cout << "Welcome To Our Library System ~ What can our system help you?\n"
             << "1. Book Checking\n2. Add New Book\n3. Remove a Book\n4. List All Book\n5. Exit\n";
        cout << "Enter Your Choice:";
        cin >> choice;

        if (choice == "2") {
            cout << "Insert the New Book's Name that you want to Add:";
            cin >> newName;
            cout << "Insert the New Book's Author that you want to Add:";
            cin >> newAuthor;
            cout << "Insert the New Book's Content that you want to Add:";
            cin >> newContent;
            book[0].setBook(newName, newAuthor, newContent);
            cout << "You successfully add a new book.";
        }
        else if (choice == "3") {
            cout << "Insert the Book's Name that you want to Remove:";
        }
        else if (choice == "4") {
            cout << "Book Name: " << book[0].getName();
            cout << "Author: " << book[0].getAuthor();
            cout << "Content: " << book[0].getContent();
        }
        else {
            cout << "Please Insert Again!!!\n";
        }
    }
    return 0;
}