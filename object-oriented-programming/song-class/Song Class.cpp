// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <string>

using namespace std;

class Song
{
    private:
        string name;
        string artist;
    public:
        void setName(string n)
        {
            name = n;
        }
        void setArtist(string a)
        {
            artist = a;
        }
        string getName()
        {
            return name;
        }
        string getArtist()
        {
            return artist;
        }
};

int main()
{
    Song song1;
    string name;
    string artist;

    cout << "Please enter the name of the song: ";
    getline(cin, name);

    cout << "Please enter the name of the artist: ";
    getline(cin, artist);

    song1.setName(name);
    song1.setArtist(artist);

    cout << "\nThe name of the song is " << song1.getName() << endl;
    cout << "The name of the artist is " << song1.getArtist() << endl;

    return 0;
}

/* SAMPLE OUTPUT
[msanc496@hills ~]$ ./a.out
Please enter the name of the song: Ring of Fire
Please enter the name of the artist: Johnny Cash

The name of the song is Ring of Fire
The name of the artist is Johnny Cash
[msanc496@hills ~]$
*/