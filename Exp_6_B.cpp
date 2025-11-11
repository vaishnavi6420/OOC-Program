#include <iostream>
using namespace std;

class LibraryItem {
protected:
    int id;
    int year;

public:
    void inputItem() {
        cin >> id >> year;
    }

    void displayItem() const {
        cout << "ID: " << id << ", Year: " << year << endl;
    }
};

class Book : public LibraryItem {
private:
    int pages;

public:
    void inputBook() {
        inputItem();
        cin >> pages;
    }

    void displayBook() const {
        displayItem();
        cout << "Pages: " << pages << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issue;

public:
    void inputMagazine() {
        inputItem();
        cin >> issue;
    }

    void displayMagazine() const {
        displayItem();
        cout << "Issue: " << issue << endl;
    }
};

int main() {
    Book b;
    Magazine m;

    b.inputBook();
    m.inputMagazine();

    b.displayBook();
    m.displayMagazine();

    return 0;
}