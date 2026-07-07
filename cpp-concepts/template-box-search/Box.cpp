// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <stdexcept>
using namespace std;

template <class ItemType>
class Box
{
	private:
		ItemType item;
	public:
		void setItem(const ItemType& newItem)
			{ item = newItem; }
		ItemType getItem() const
			{ return item; }
};

Box<int> findBox(Box<int> boxes[], int size, int target)
{
	if (target < 0)
		throw logic_error("Target cannot be negative.");

	int i = 0;
	bool found = false;
	while (!found && i < size)
	{
		if (boxes[i].getItem() == target)
			found = true;
		else
			i++;
	}
	if (!found)
	throw logic_error("Target not found in any box.");

	return boxes[i];
}

int main()
{
	const int SIZE = 10;
	Box<int> Boxes[SIZE];
	Box<int> searchBox;

	Boxes[0].setItem(123456789);
	Boxes[1].setItem(987654321);

	int target;

	cout << "Enter a social security number to search for: ";
	cin >> target;

	try
	{
		searchBox = findBox(Boxes, SIZE, target);
		cout << "Found SSN : " << searchBox.getItem() << endl;
	}
	catch (logic_error logErr)
	{
		cout << "Error: " << logErr.what() << endl;
	}
	return 0;
}

/*
SAMPLE OUTPUT 1:
Enter a social security number to search for: -1
Error: Target cannot be negative.
SAMPLE OUTPUT 2:
Enter a social security number to search for: 123
Error: Target not found in any box.
SAMPLE OUTPUT 3:
Enter a social security number to search for: 123456789
Found SSN : 123456789
*/