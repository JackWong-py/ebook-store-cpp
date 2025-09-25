#include <iostream>
#include "Book.h"
using namespace std;

int get_number_only() //This is a input validate function for number only (Jack)
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

int main() {
    string name, author, content;
    int choice;
    Book book[100];
    cout << "Hello Welcome to Our Ebook Store!" << endl;
    return 0;
}
