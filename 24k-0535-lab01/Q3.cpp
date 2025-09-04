#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;  //dynamically allocated array
    int size;

public:
    //Constructor
    Exam(int n) {
        size = n;
        marks = new int[size];
        for (int i = 0; i < size; i++) {
            marks[i] = 0; 
        }
    }

    //Destructor
    ~Exam() {
        delete[] marks;
    }

    //Set marks
    void setMarks(int index, int value) {
        if (index >= 0 && index < size) {
            marks[index] = value;
        }
    }

    // Display marks
    void display() const {
        cout << "Marks: ";
        for (int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    //object
    Exam e1(3);
    e1.setMarks(0, 85);
    e1.setMarks(1, 90);
    e1.setMarks(2, 95);

    cout << "e1 (Original): ";
    e1.display();
    
    //shallow copy
    Exam e2 = e1;

    cout << "e2 (Copied from e1): ";
    e2.display();

    //changing marks 
    e2.setMarks(1, 50);
    cout << "\nAfter modifying e2:\n";
    cout << "e1 (Original): ";
    e1.display();
    cout << "e2 (Modified): ";
    e2.display();
    
    cout << "\nChanging e2 also changed e1 marks (shallow copy problem)\n";

    return 0;
}

