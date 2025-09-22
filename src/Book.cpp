#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(){
  bookID = 0;
  name = "";
  author = "";
  content = "";
}

int Book::bookCount = 0;

void Book::setBook(string n, string a, string c){
  bookCount++;
  bookID = bookCount;
  name = n;
  author = a;
  content = c;
}

void Book::updateBook(int id, string n, string a, string c){
  bookID = id;
  name = n;
  author = a;
  content = c;
}

int Book::getBookID(){
  return bookID;
}

string Book::getName(){
  return name;
}

string Book::getAuthor(){
  return author;
}

string Book::getContent(){
  return content;
}

void Book::reduceBookCount(){
  bookCount--;
}