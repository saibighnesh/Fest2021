#include <iostream>
using namespace std;

int binarySearch(int array[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = (start + (end - start) / 2); // mid indexation of the list
        if (array[mid] == key)
            return mid;
        if (array[mid] > key)
            return binarySearch(array, start, mid - 1, key);
        return binarySearch(array, mid + 1, end, key);
    }
    return -1;
}

int exponentialSearch(int array[], int start, int end, int key)
{
    if ((end - start) <= 0)
        return -1;
    int i = 1;
    while (i < (end - start))
    {
        if (array[i] < key)
            i *= 2;
        else
            break; // when array[i] corsses the key element
    }
    // reach to an interval between i/2 and i and than do a small binary search there to find the element.
    return binarySearch(array, i / 2, i, key); // search item in the smaller range
}

int main()
{
    int n, searchKey, index;
    cout << "Enter size of the list: ";
    cin >> n;

    // create an array of size n
    int *arr = new int[n];
    cout << "Enter elements of the list: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter search key: ";
    cin >> searchKey;

    if ((index = exponentialSearch(arr, 0, n, searchKey)) >= 0)
        cout << "Item found at position: " << index << " in the list" << endl;
    else
        cout << "Item is not found in the list." << endl;
}