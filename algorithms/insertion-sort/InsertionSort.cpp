// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long accessCount = 0; // global counter

void insertionSort(int theArray[], int n)
{
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        int nextItem = theArray[unsorted];
        accessCount++; // read theArray[unsorted]

        int loc = unsorted;

        // Ascending order
        while ((loc > 0) && (theArray[loc - 1] > nextItem))
        {
            accessCount++; // read theArray[loc - 1] for comparison
            theArray[loc] = theArray[loc - 1];
            accessCount++; // write theArray[loc]

            loc--;
        }

        theArray[loc] = nextItem;
        accessCount++; // write nextItem
    }
}

void fillRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

int main()
{
    srand(time(0));

    const int size1 = 10;
    const int size2 = 50;
    const int size3 = 100;

    int arr1[size1];
    int arr2[size2];
    int arr3[size3];

    fillRandom(arr1, size1);
    fillRandom(arr2, size2);
    fillRandom(arr3, size3);

    accessCount = 0;
    insertionSort(arr1, size1);
    cout << "Array of size 10 -> Accesses: " << accessCount << endl;

    accessCount = 0;
    insertionSort(arr2, size2);
    cout << "Array of size 50 -> Accesses: " << accessCount << endl;

    accessCount = 0;
    insertionSort(arr3, size3);
    cout << "Array of size 100 -> Accesses: " << accessCount << endl;

    return 0;
}

/* MY SAMPLE OUTPUT (Answer to question 5)
Array of size 10 -> Accesses: 96
Array of size 50 -> Accesses: 1793
Array of size 100 -> Accesses: 7611
*/