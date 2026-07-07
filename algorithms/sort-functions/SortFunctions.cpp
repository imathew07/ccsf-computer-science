// Mateo Sanchez Sinche, CS 110C

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long accessCount = 0; // Global counter

// insertionSort function with array access counting
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

// merge function with array access counting
void merge(int theArray[], int first, int mid, int last)
{
	const int MAX_SIZE = 1000; // Can be adjusted based on expected input size
    int tempArray[MAX_SIZE];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first;

    // Merge the two sorted halves
    while ((first1 <= last1) && (first2 <= last2))
    {
        accessCount += 2; // Reading theArray[first1] and theArray[first2]
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            accessCount++; // Writing to tempArray
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            accessCount++; // Writing to tempArray
            first2++;
        }
        index++;
    }

    // Copy remaining elements of the first half, if any
    while (first1 <= last1)
    {
        tempArray[index] = theArray[first1];
        accessCount += 2; // Read theArray[first1], write tempArray[index]
        first1++;
        index++;
    }

    // Copy remaining elements of the second half, if any
    while (first2 <= last2)
    {
        tempArray[index] = theArray[first2];
        accessCount += 2; // Read theArray[first2], write tempArray[index]
        first2++;
        index++;
    }

    // Copy merged elements back into original array
    for (index = first; index <= last; index++)
    {
        theArray[index] = tempArray[index];
        accessCount++; // Writing back to original array
    }
}

// mergeSort function
void mergeSort(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        mergeSort(theArray, first, mid);
        mergeSort(theArray, mid + 1, last);
        merge(theArray, first, mid, last);
    }
}

// countingSort function with array access counting
void countingSort(int theArray[], int n)
{
    const int RANGE = 101; // numbers 0-100
    int count[RANGE] = { 0 };

    // Count occurrences of each value
    for (int i = 0; i < n; i++)
    {
        count[theArray[i]]++;
        accessCount++;         // Only reading theArray[i]
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int value = 0; value < RANGE; value++)
    {
        while (count[value] > 0)
        {
            theArray[index] = value;
            accessCount++;      // Writing to the original array
            index++;
            count[value]--;
        }
    }
}

void fillRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 101;  // Random numbers 0-100
}

// Function to copy one array to another
void copyArray(int source[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const int sizes[] = { 8, 32, 128 };
    const int numSizes = 3;
    const int trials = 3;

    cout << "Format:" << endl;
    cout << "Sort | Size | Pass1 | Pass2 | Pass3 | Average" << endl;
    cout << "------------------------------------------------------------" << endl;

    // INSERTION
    for (int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        long long pass[3];

        for (int t = 0; t < trials; t++)
        {
            int arr[128];
            fillRandom(arr, n);

            int temp[128];
            copyArray(arr, temp, n);

            accessCount = 0;
            insertionSort(temp, n);
            pass[t] = accessCount;
        }

        long long avg = (pass[0] + pass[1] + pass[2]) / 3;

        cout << "Insertion | " << n << " | "
            << pass[0] << " | "
            << pass[1] << " | "
            << pass[2] << " | "
            << avg << endl;
    }

    cout << "----------------------------------------" << endl;

    // MERGE
    for (int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        long long pass[3];

        for (int t = 0; t < trials; t++)
        {
            int arr[128];
            fillRandom(arr, n);

            int temp[128];
            copyArray(arr, temp, n);

            accessCount = 0;
            mergeSort(temp, 0, n - 1);
            pass[t] = accessCount;
        }

        long long avg = (pass[0] + pass[1] + pass[2]) / 3;

        cout << "Merge     | " << n << " | "
            << pass[0] << " | "
            << pass[1] << " | "
            << pass[2] << " | "
            << avg << endl;
    }

    cout << "----------------------------------------" << endl;

    // COUNTING
    for (int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        long long pass[3];

        for (int t = 0; t < trials; t++)
        {
            int arr[128];
            fillRandom(arr, n);

            int temp[128];
            copyArray(arr, temp, n);

            accessCount = 0;
            countingSort(temp, n);
            pass[t] = accessCount;
        }

        long long avg = (pass[0] + pass[1] + pass[2]) / 3;

        cout << "Counting  | " << n << " | "
            << pass[0] << " | "
            << pass[1] << " | "
            << pass[2] << " | "
            << avg << endl;
    }

    cout << "----------------------------------------" << endl;

    return 0;
}

/* SAMPLE OUTPUT (Random values will differ each run):
Format:
Sort | Size | Pass1 | Pass2 | Pass3 | Average
------------------------------------------------------------
Insertion | 8 | 32 | 46 | 34 | 37
Insertion | 32 | 602 | 540 | 548 | 563
Insertion | 128 | 8478 | 7860 | 8432 | 8256
----------------------------------------
Merge     | 8 | 88 | 86 | 88 | 87
Merge     | 32 | 602 | 598 | 602 | 600
Merge     | 128 | 3416 | 3424 | 3425 | 3421
----------------------------------------
Counting  | 8 | 16 | 16 | 16 | 16
Counting  | 32 | 64 | 64 | 64 | 64
Counting  | 128 | 256 | 256 | 256 | 256
----------------------------------------
*/