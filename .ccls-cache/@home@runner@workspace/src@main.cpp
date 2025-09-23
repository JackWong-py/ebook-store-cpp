#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book book[100];
    book[0].setBook("a","bse","dasifhdsnfusd");
    cout << "Hello Welcome to Our Ebook Store!" << endl;
    cout << Book::bookCount << endl;
    return 0;
}
