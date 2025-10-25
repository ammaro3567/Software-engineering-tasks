#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;
    double price;
    static int bookCount;

public:
    Book(string t, string a, int p, double pr) {
        title = t;
        author = a;
        pages = p;
        price = pr;
        bookCount++;
    }

    Book(const Book &b) {
        title = b.title;
        author = b.author;
        pages = b.pages;
        price = b.price;
        bookCount++;
    }

    static int getBookCount() {
        return bookCount;
    }

    void print()  {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
        cout << "Price: " << price << endl;
    }
};

int Book::bookCount = 0;

int main() {
    Book b1("The Alchemist", "Paulo Coelho", 208, 9.99);
    Book b2(b1);

    b1.print();
    cout << endl;
    b2.print();

    cout << "\nTotal books: " << Book::getBookCount() << endl;
    return 0;
}
