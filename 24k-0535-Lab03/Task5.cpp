#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(string s) : song(s), next(nullptr) {}
};

class Playlist {
    Node* tail;
public:
    Playlist() : tail(nullptr) {}

    void addSong(const string& song) {
        Node* newNode = new Node(song);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() const {
        if (!tail) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Playlist songs:\n";
        do {
            cout << "- " << temp->song << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }

    void playSongs(int n) const {
        if (!tail) {
            cout << "Playlist is empty, no songs to play.\n";
            return;
        }
        Node* current = tail->next;
        cout << "Playing songs:\n";
        for (int i = 0; i < n; ++i) {
            cout << current->song << endl;
            current = current->next;
        }
    }

    ~Playlist() {
        if (!tail) return;
        Node* current = tail->next;
        Node* temp;
        do {
            temp = current;
            current = current->next;
            delete temp;
        } while (current != tail->next);
    }
};

int main() {
    Playlist playlist;
    playlist.addSong("Shape of You - Ed Sheeran");
    playlist.addSong("Blinding Lights - The Weeknd");
    playlist.addSong("Levitating - Dua Lipa");
    playlist.addSong("Good 4 U - Olivia Rodrigo");

    playlist.display();

    playlist.playSongs(10);

    return 0;
}
