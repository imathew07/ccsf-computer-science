// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <string>
using namespace std;

// Prints only the first character repeatedly, not the whole reversed string.
void reverseString(string s)
{
	int length = s.size();
	if (length > 0)
	{
		cout << s[0];
		reverseString(s.substr(0, length - 1));
	}
}

// Correctly prints the string in reverse order.
void reverseString2(string s)
{
	int length = s.size();
	if (length > 0)
	{
		reverseString2(s.substr(1, length - 1));
		cout << s[0];
	}
}


int main()
{
	string s = "cat";
	cout << "Original string: " << s << endl;
	cout << "Reversed string (Method 1): ";
	reverseString(s);
	cout << endl;
	cout << "Reversed string (Method 2): ";
	reverseString2(s);
	cout << endl;
	return 0;
}

/* SAMPLE OUTPUT
Original string: cat
Reversed string (Method 1): ccc
Reversed string (Method 2): tac
*/