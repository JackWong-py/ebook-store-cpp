#include <iostream>
using namespace std;

class Book{
private:
  int bookID;
  string name;
  string author;
  string content;

public:
  static int bookCount;
  Book();
  void setBook(string n, string a, string c);
  void updateBook(int id, string n, string a, string c);
  int getBookID();
  string getName();
  string getAuthor();
  string getContent(); 
  static void reduceBookCount();
};