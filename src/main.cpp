#include <iostream>
#include "Book.h"

using namespace std;

int get_number_only();
void read_book(Book book[]);
void add_book(Book book[]);
void remove_book(Book book[]);
string get_letters_only();
void edit_book(Book book[]);

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
                            edit_book(book);
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

void edit_book(Book book[])
//This function is to edit book.
{
    if (Book::bookCount == 0)
    {
        cout << "There is no book to edit.\n";
        return;
    }
    int choice;
    cout << "\nWhich book do you want to edit?\n";
    for (int i = 0; i < Book::bookCount; i++)
    {
        cout << i + 1 << ". " << book[i].getName()
             << " by " <<  book[i].getAuthor() << endl;
    }
    cout << "Enter choice(number): ";
    choice = get_number_only();

    if (choice <= 0 || choice > Book::bookCount)
    {
        cout << "Invalid book selection!\n";
        return;
    }
    int editChoice;
    cout << "What do you want to edit?\n"
    << "1. Name\n"
    << "2. Author\n"
    << "3. Content\n"
    << "Enter choice (number): ";
    editChoice = get_number_only();

    string newValue;
    cin.ignore();

    switch (editChoice)
    {
            case 1:
                cout << "Enter new name:\n";
                getline(cin, newValue);
                book[choice - 1].setName(newValue);
                cout << "Book name updated successfully.";
                break;
            case 2:
                cout << "Enter new author:\n";
                getline(cin, newValue);
                book[choice - 1].setName(newValue);
                cout << "Book author updated successfully.";
                break;
            case 3:
                cout << "Enter new content:\n";
                getline(cin, newValue);
                book[choice - 1].setName(newValue);
                cout << "Book content updated successfully.";
                break;
            default:
                cout << "Invalid edit choice!";
                break;
    }
}
