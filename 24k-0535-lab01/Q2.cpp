#include <iostream>
using namespace std;

class Box {
private:
    int* volume;  // dynamically allocated integer

public:
    //a) Default constructor
    Box() {
        volume = new int(0);
    }
    //b) Parameterized constructor
    Box(int v) {
        volume = new int(v);
    }
    //c) Copy constructor
    Box(const Box& other) {
        volume = new int(*(other.volume));
    }
    //destructor
    ~Box() {
        delete volume;
    }

    //setter and getter
    void setVolume(int v) {
        *volume = v;
    }
    int getVolume() const {
        return *volume;
    }

    //display 
    void display() const {
        cout << "Box Volume: " << *volume << endl;
    }
};

int main() {
    Box b1;
    cout << "b1 (Default): ";
    b1.display();

    Box b2(50);
    cout << "b2 (Parameterized): ";
    b2.display();

    Box b3 = b2;
    cout << "b3 (Copied from b2): ";
    b3.display();

    b3.setVolume(100);
    cout << "\nAfter modifying b3:\n";
    cout << "b2 (Original): ";
    b2.display();
    cout << "b3 (Modified): ";
    b3.display();

    return 0;
}
