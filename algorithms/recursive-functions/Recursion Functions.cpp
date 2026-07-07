// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <string>
using namespace std;

// A recursive C++ function that writes the digits of a positive
// decimal integer in reverse order.
void writeDigitsReverse(int n)
{
	// Base case: if n is a single digit, print it
	if (n < 10)
	{
		cout << n;
		return;
	}
	
	// Recursive case: print the last digit and call the
	// function with the rest of the number
	cout << n % 10;
	writeDigitsReverse(n / 10);
}

// A recursive C++ function that writes a string backward
// by printing the last character first.
void writeBackward(string s)
{
	cout << "Enter writeBackward with string: " << s << endl;
	// Base case: if the string is empty, do nothing
	if (s.length() > 0)
	{
		cout << "About to write last character of string: "
			<< s << endl;
		// Write the last character of s
		// Recursive call with all but the last character of s
		cout << s[s.length() - 1] << endl;
		writeBackward(s.substr(0, s.length() - 1));
	}

	cout << "Leave writeBackward with string: " << s << endl;
}

// A recursive C++ function that writes a string backward
// by printing the first character last.
void writeBackward2(string s)
{
	cout << "Enter writeBackward2 with string: "
		 << s << endl;
	if (s.length() > 0)
	{
		writeBackward2(s.substr(1, s.length() - 1));
		cout << "About to write first character of string: "
			 << s << endl;
		cout << s[0] << endl;
	}

	cout << "Leave writeBackward2 with string: " << s << endl;
}

// A recursive C++ function that returns the sum of the integers
// from start to end, inclusive.
int sumRange(int start, int end)
{
	// Base case: if start equals end, return start
	if (start == end)
	{
		return start;
	}
	else
	{
		// Recursive case: return start plus the sum of the range
		return start + sumRange(start + 1, end);
	}
}

int main()
{
	cout << "Reverse digits of 2015: ";
	writeDigitsReverse(2015);
	cout << "\n\n";

	cout << "Testing writeBackward:\n\n";
	writeBackward("cat");
	cout << "\n";

	cout << "Testing writeBackward2:\n\n";
	writeBackward2("cat");
	cout << "\n";

	cout << "Sum from 3 to 6: ";
	cout << sumRange(3, 6) << endl;

	return 0;
}

/* SAMPLE OUTPUT
Reverse digits of 2015: 5102

Testing writeBackward:

Enter writeBackward with string: cat
About to write last character of string: cat
t
Enter writeBackward with string: ca
About to write last character of string: ca
a
Enter writeBackward with string: c
About to write last character of string: c
c
Enter writeBackward with string:
Leave writeBackward with string:
Leave writeBackward with string: c
Leave writeBackward with string: ca
Leave writeBackward with string: cat

Testing writeBackward2:

Enter writeBackward2 with string: cat
Enter writeBackward2 with string: at
Enter writeBackward2 with string: t
Enter writeBackward2 with string:
Leave writeBackward2 with string:
About to write first character of string: t
t
Leave writeBackward2 with string: t
About to write first character of string: at
a
Leave writeBackward2 with string: at
About to write first character of string: cat
c
Leave writeBackward2 with string: cat

Sum from 3 to 6: 18
*/