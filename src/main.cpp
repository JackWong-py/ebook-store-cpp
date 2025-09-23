#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book book[100];
    cout << "Hello Welcome to Our Ebook Store!" << endl;
    cout << Book::bookCount << endl;
    return 0;
}
