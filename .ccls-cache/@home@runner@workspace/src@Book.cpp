#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(){
  name = "";
  author = "";
  content = "";
}

int Book::bookCount = 0;

void Book::setBook(string n, string a, string c){
  bookCount++;
  name = n;
  author = a;
  content = c;
}

void Book::setName(string n){
  name = n;
}

void Book::setAuthor(string a){
  author = a;
}

void Book::setContent(string c){
  content = c;
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
  bookCount -= 2;
}