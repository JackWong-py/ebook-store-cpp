#include <iostream>
#include "Book.h"
using namespace std;

int get_number_only();
void read_book(Book book[]);
void add_book(Book book[]);
void remove_book(Book book[]);
string get_letters_only();

int main() {
    string name, author, content;
    int choice1, choice2;
    Book book[100];
    cout << "Hello Welcome to ERead!" << endl;
    do{
        cout << "\n1. Read Book" << "\n2. Edit Book List" << "\n3. Exit" << "\nEnter Choice(In Number): ";
        choice1 = get_number_only();
        switch(choice1){
            case 1:{
                read_book(book);
                break;
            }
            case 2:{
                do{
                    cout << "\nChoice List:" << endl;
                    cout << "1. Add Book\n" << "2. Update Book\n" << "3. Remove Book\n" << "4. Back" << endl;
                    cout << "Enter Choice(In Number): ";
                    choice2 = get_number_only();
                    switch(choice2){
                        case 1:{
                            add_book(book);
                            break;
                        }
                        case 2:{
                            break;
                        }
                        case 3:{
                            remove_book(book);
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:{
                            cout << "Invalid Input! Please eneter again." << endl;
                        }
                    }
                }
                    while(choice2 <= 0 || choice2 > 4);
            }
            case 3:{
                cout << "Thank you for using ERead. See you next time" << endl;
                break;
            }
            default:{
                cout << "Invalid Input! Please eneter again."<< endl;
            }
        }
    }
        while(choice1 != 3);
    return 0;
}

int main1() { //This is our main system (Book Checking, Book Adding, Book Removing, Book listing)
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
        if (choice == "3") {
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

int get_number_only() //This is a input validate function for number only
{
    int number;
    if (cin >> number){
        return number;
    }
    else{
        return 0;
    }
}

void read_book(Book book[]){
    int input = 0;
    if(Book::bookCount > 0){
        do{
            cout << "\nBook List" << endl;
            for(int i = 0; i < Book::bookCount; i++){
                cout << i+1 << ". " << book[i].getName() << " " << book[i].getAuthor() << endl;
            }
            cout << "Choose a Book(Enter in number): ";
            input = get_number_only();
            if(input > 0 && input <= Book::bookCount){
                cout << "\nBook Name\t: " << book[input-1].getName() << "\nAuthor\t: " << book[input-1].getAuthor() << "\n    " << book[input-1].getContent() << endl;
            }
            else {
                cout << "Invalid Input! Please eneter again.";
            }
        }
            while(input <= 0 || input > Book::bookCount);
    }
    else {
        cout << "The book list is empty! Please add the book list" << endl;
    }
}

void add_book(Book book[]){
    string name, author, content;
    cout << "Insert Book's Name: ";
    cin.ignore();
    getline(cin, name);
    while(name.empty()){
        cout << "Invalid Input" << endl;
        cout << "Insert Book's Name: ";
        getline(cin, name);
    }
    cout << "Insert Book's Author: ";
    author = get_letters_only();
    while(author.empty()){
        cout << "Invalid Input" << endl;
        cout << "Insert Book's Author: ";
        author = get_letters_only();
    }
    cout << "Insert Book's Content: ";
    getline(cin, content);
    while(content.empty()){
        cout << "Invalid Input" << endl;
        cout << "Insert Book's Content: ";
        getline(cin, content);
    }
    book[Book::bookCount].setBook(name, author, content);
    cout << "You successfully add a new book.\n";
}

void remove_book(Book book[]){
    int input;
    if(Book::bookCount > 0){
        do{
            cout << "\nBook List" << endl;
            for(int i = 0; i < Book::bookCount; i++){
                cout << i+1 << ". " << book[i].getName() << " " << book[i].getAuthor() << endl;
            }
            cout << "Choose a Book(Enter in number): ";
            input = get_number_only();
            if(input > 0 || input <= Book::bookCount){
                input -= 1;
                for(int i = input;i < Book::bookCount; i++){
                    if(i+1 == Book::bookCount){
                        book[i].setBook("","","");
                        Book::reduceBookCount();
                    }
                    else
                        book[i] = book[i+1];
                }
                break;
            }
            else {
                cout << "Invalid Input! Please eneter again.";
            }
        }
            while(input <= 0 || input > Book::bookCount);
    }
    else {
        cout << "The book list is empty! Please add the book list" << endl;
    }    
}

string get_letters_only()
//This function validate alphabet input only.
//It return "" if user input contain other than alphabet except space
{
    string name;
    getline(cin, name);
    for(char c: name){
        if(!isalpha(c)&& c != ' '){
            return "";}
    }return name;
}
