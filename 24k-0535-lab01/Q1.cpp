#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string title;
    int year;
    int AuthorCount;   
    string* authors; //dynamic array of authors

public:
    //Default constructor
    ResearchPaper() {
        title = "Untitled";
        year = 0;
        AuthorCount = 0;
        authors = nullptr;
    }

    //Parameterized Constructor 
    ResearchPaper(string t, int y, string arr[], int n) {
        title = t;
        year = y;
        AuthorCount = n;
        if (AuthorCount > 0) {
            authors = new string[AuthorCount];
            for (int i = 0; i < AuthorCount; i++) {
                authors[i] = arr[i];
            }
        } else {
            authors = nullptr;
        }
    }

    //deep copy
    ResearchPaper(const ResearchPaper& other) {
        title = other.title;
        year = other.year;
        AuthorCount = other.AuthorCount;
        if (AuthorCount > 0) {
            authors = new string[AuthorCount];
            for (int i = 0; i < AuthorCount; i++) {
                authors[i] = other.authors[i];
            }
        } else {
            authors = nullptr;
        }
    }

    //Assignment operator (deep copy)
    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this == &other) return *this;
        delete[] authors; 

        title = other.title;
        year = other.year;
        AuthorCount = other.AuthorCount;

        if (AuthorCount > 0) {
            authors = new string[AuthorCount];
            for (int i = 0; i < AuthorCount; i++) {
                authors[i] = other.authors[i];
            }
        } else {
            authors = nullptr;
        }

        return *this;
    }

    //Destructor
    ~ResearchPaper() {
        delete[] authors;
    }

    void display() const {
        cout << "Title: " << title << " (" << year << ")\nAuthors: ";
        if (AuthorCount == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < AuthorCount; i++) {
                cout << authors[i];
                if (i < AuthorCount - 1) cout << ", ";
            }
        }
        cout << "\n\n";
    }
};

int main() {
    string authors1[] = {"Ali", "Hassan"};
    ResearchPaper p1("Compter Science in 2025", 2025, authors1, 2);

    cout << "p1 (Original):\n";
    p1.display();

    ResearchPaper p2 = p1;
    cout << "p2 (Copied from p1):\n";-
    p2.display();

    string authors2[] = {"Mujtaba", "Asad"};
    ResearchPaper p3("AI Introducution", 2022, authors2, 2);
    cout << "p3 (Before assignment):\n";
    p3.display();

    p3 = p1;
    cout << "p3 (After assignment from p1):\n";
    p3.display();

    return 0;
}

