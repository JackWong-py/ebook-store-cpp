#include <iostream>
using namespace std;

class Book{
private:
  string name;
  string author;
  string content;

public:
  static int bookCount;
  Book();
  void setBook(string n, string a, string c);
  void setName(string n);
  void setAuthor(string a);
  void setContent(string c); 
  string getName();
  string getAuthor();
  string getContent(); 
  static void reduceBookCount();
};