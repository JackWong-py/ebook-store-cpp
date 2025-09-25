#include <iostream>
#include "Book.h"
using namespace std;


int get_number_only() //This is a input validate function for number only 
{
    int number;

    cout << "Enter a number: ";
    if (cin >> number){
        return number;
    }
    else{
        return 0;
    }
}

/*int main() {
    string name, author, content;
    int choice;
    Book book[100];
    cout << "Hello Welcome to Our Ebook Store!" << endl;
    return 0;
}*/

int main() { //This is our main system (Book Checking, Book Adding, Book Removing, Book listing)
    string choice;
    string Remove;
    string Search;
    string newName, newAuthor, newContent;
     int BookCount=0;

    Book book[100]; 

    while (true) {
        cout << "Welcome To Our Library System ~ What can our system help you?\n"
             << "1. Book Checking\n2. Add New Book\n3. Remove a Book\n4. List All Book\n5. Exit\n";
        cout << "Enter Your Choice:";
        cin >> choice;
        
        if (choice=="1"){
        	cout << "What is the Book's Name that you want to check:";
        	cin >> Search;
        	bool found = false;
        	for (int a=0; a<100; a++){
        		if (book[a].getName()==Search){
        			cout << "Book Name: " << book[a].getName() << "\n";
            		cout << "Author: " << book[a].getAuthor() << "\n";
            		cout << "Content: " << book[a].getContent() << "\n"; 
            		found = true;
            		break;
            if (!found){
            	cout<<"Book not found!\n";
					}
				}
			}
		}

        else if (choice == "2") {
            cout << "Insert the New Book's Name that you want to Add:";
            cin >> newName;
            cout << "Insert the New Book's Author that you want to Add:";
            cin >> newAuthor;
            cout << "Insert the New Book's Content that you want to Add:";
            cin >> newContent;
            book[BookCount].setBook(newName, newAuthor, newContent);
            BookCount++;
            cout << "You successfully add a new book.\n";
        }
        else if (choice == "3") {
            cout << "Insert the Book's Name that you want to Remove:";
            cin >> Remove;

            bool found = false;
            for (int i = 0; i < 100; i++) {
                if (book[i].getName() == Remove) {
                    book[i].setBook("", "", ""); 
                    cout << "Book \"" << Remove << "\" removed successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!\n";
            }
        }
        else if (choice == "4") {
            int displayCount = 0;
            for (int y=0; y < 100; y++){
                if (book[y].getName() != "" && book[y].getName() != " ") {
                    displayCount++;
                    cout << displayCount << ". Book Name: " << book[y].getName() << "\n";
                    cout << "   Author: " << book[y].getAuthor() << "\n";
                    cout << "   Content: " << book[y].getContent() << "\n\n";
                }
            }
            cout << "Which Do You Want To Read:";
        }
        else {
            cout << "Please Insert Again!!!\n";
        }
    }
    return 0;
}
