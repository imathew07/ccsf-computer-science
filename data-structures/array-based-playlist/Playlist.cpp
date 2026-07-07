// Array-based List Class for Playlists
// Max Luttrell CS 110C
// Mateo Sanchez Sinche, CS 110C

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE = 2;
    ItemType *list;
    int numItems;
    int maxItems;
public:
    // Constructor and destructor
    List() {
        numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE];
    }
    ~List() { delete[] list; }

    // List member functions
    bool isEmpty()  const { return numItems == 0; }
    int getLength() const { return numItems; }

	void setEntry(int pos, const ItemType& item);   //implemented
    bool remove(int pos);                           //implemented
    bool insert(int pos, const ItemType& item);     //modified
    ItemType getEntry(int pos) const;

    void clear() { numItems = 0; }
};

// setEntry FUNCTION IMPLEMENTATION
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
    if (pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: setEntry() using invalid position");
    }
    list[pos - 1] = item;
}

// remove FUNCTION IMPLEMENTATION
template<class ItemType>
bool List<ItemType>::remove(int pos) {
    if ((pos < 1) || (pos > numItems))
        return false;

    for (int i = pos; i < numItems; i++)
        list[i - 1] = list[i];

    numItems--;
    return true;
}

// insert FUNCTION IMPLEMENTATION MODIFIED TO RESIZE THE ARRAY AS NEEDED
template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd = ((pos > 0) && (pos <= numItems + 1));
    if (!canAdd) return false;

    //Resize the array if necessary
    if (numItems == maxItems) {
        int newSize = maxItems + CHUNK_SIZE;
        ItemType* newList = new ItemType[newSize];

        for (int i = 0; i < numItems; i++)
            newList[i] = list[i];

        delete[] list;
        list = newList;
        maxItems = newSize;
    }

    // Shift items down to make room for new item
    for (int i = numItems; i >= pos; i--)
        list[i] = list[i - 1];

    // Insert new item
    list[pos - 1] = item;
    numItems++;
    return true;
}

// getEntry function implementation
template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if (pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos - 1];
}

// getTrack
int getTrack()
{
    bool inputCheck;
    int trackNumber;

    do
    {
        inputCheck = true;
        cout << "\nPlease enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}

int main()
{
    List<string> songs;
    char goAgain = 'y';
    int trackNumber;
    string trackName;

    // Insert some songs into our list
    songs.insert(1, "One More Saturday Night");
    songs.insert(1, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(1, "California Love");

    cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
	cout << "Current Playlist:\n";
    for (int i = 1; i <= songs.getLength(); i++)
		cout << i << ": " << songs.getEntry(i) << endl;

	// Test setEntry function
    cout << "\n--- Testing setEntry to change first song to 'New Song' ---\n";
	cout << "Changing song at position 1...\n";
	songs.setEntry(1, "New Song");
	cout << "Playlist after setEntry:\n";
	for (int i = 1; i <= songs.getLength(); i++)
		cout << i << ": " << songs.getEntry(i) << endl;
	// Test exception handling in setEntry
	cout << "\n--- Testing exception for invalid setEntry ---\n";
	try {
        cout << "Changing song at position 10...\n";
		songs.setEntry(10, "Invalid Song");
	}
	catch (invalid_argument &invArg) {
		cout << invArg.what() << endl;
	}

    // Test remove function
	cout << "\n--- Testing remove function ---\n";
    cout << "Removing song at position 2...\n";
    songs.remove(2);
    cout << "Playlist after remove:\n";
    for (int i = 1; i <= songs.getLength(); i++)
        cout << i << ": " << songs.getEntry(i) << endl;

	// Test insert dynamic resizing
	cout << "\n--- Testing insert beyond initial CHUNK_SIZE(2) ---\n";
	// CHUNK_SIZE is 2

    cout << "Inserting Extra Song 1 at position 2...\n";
	songs.insert(2, "Extra Song 1");
    cout << "Inserting Extra Song 2 at position 3...\n";
	songs.insert(3, "Extra Song 2");
    cout << "Inserting Extra Song 3 at position 4...\n";
	songs.insert(4, "Extra Song 3");
    cout << "Inserting Extra Song 4 at position 5...\n";
    songs.insert(5, "Extra Song 4");

	cout << "Playlist after inserting more songs:\n";
	for (int i = 1; i <= songs.getLength(); i++)
		cout << i << ": " << songs.getEntry(i) << endl;

    // Main loop original
    while (goAgain != 'n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    cout << "Rock on!\n";
    return 0;
}

/* SAMPLE OUTPUT
[msanc496@hills ~]$ ./a.out
Welcome!  There are 4 tracks.
Current Playlist:
1: California Love
2: Friday I'm in Love
3: One More Saturday Night
4: Sunday Morning Coming Down

--- Testing setEntry to change first song to 'New Song' ---
Changing song at position 1...
Playlist after setEntry:
1: New Song
2: Friday I'm in Love
3: One More Saturday Night
4: Sunday Morning Coming Down

--- Testing exception for invalid setEntry ---
Changing song at position 10...
ERROR: setEntry() using invalid position

--- Testing remove function ---
Removing song at position 2...
Playlist after remove:
1: New Song
2: One More Saturday Night
3: Sunday Morning Coming Down

--- Testing insert beyond initial CHUNK_SIZE(2) ---
Inserting Extra Song 1 at position 2...
Inserting Extra Song 2 at position 3...
Inserting Extra Song 3 at position 4...
Inserting Extra Song 4 at position 5...
Playlist after inserting more songs:
1: New Song
2: Extra Song 1
3: Extra Song 2
4: Extra Song 3
5: Extra Song 4
6: One More Saturday Night
7: Sunday Morning Coming Down

Please enter the track number you'd like to view: 1
Your track name is New Song
Go again? (y/n) n
Rock on!
*/