#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int totalCopies;
    int availableCopies;

    void inputBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Total Copies: ";
        cin >> totalCopies;
        availableCopies = totalCopies;
    }

    void displayBook() const {
        cout << setw(5) << id << " | " << setw(20) << title 
             << " | " << setw(15) << author 
             << " | " << setw(5) << availableCopies << "/" << totalCopies << endl;
    }
};

class Library {
    vector<Book> books;

public:
    Library() {
        loadFromFile();
    }

    void addBook() {
        Book b;
        b.inputBook();
        books.push_back(b);
        saveToFile();
        cout << "Book added successfully!\n";
    }

    void displayAllBooks() {
        cout << "\nID   | Title                | Author          | Avail/Total\n";
        cout << "-------------------------------------------------------------\n";
        for (const auto& b : books) {
            b.displayBook();
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;
        for (auto& b : books) {
            if (b.id == id) {
                b.displayBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (auto& b : books) {
            if (b.id == id) {
                if (b.availableCopies > 0) {
                    b.availableCopies--;
                    saveToFile();
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "No copies available.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (auto& b : books) {
            if (b.id == id) {
                if (b.availableCopies < b.totalCopies) {
                    b.availableCopies++;
                    saveToFile();
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "All copies are already in library.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

private:
    void saveToFile() {
        ofstream fout("library.dat", ios::binary | ios::trunc);
        for (auto& b : books) {
            fout.write((char*)&b, sizeof(Book));
        }
        fout.close();
    }

    void loadFromFile() {
        ifstream fin("library.dat", ios::binary);
        if (!fin) return;
        Book b;
        while (fin.read((char*)&b, sizeof(Book))) {
            books.push_back(b);
        }
        fin.close();
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: lib.addBook(); break;
        case 2: lib.displayAllBooks(); break;
        case 3: lib.searchBook(); break;
        case 4: lib.issueBook(); break;
        case 5: lib.returnBook(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
