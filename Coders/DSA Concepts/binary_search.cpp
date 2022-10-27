#include <iostream>
using namespace std;
void insertionSort(int *arr, int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}
void binarySearch(int x, int *arr, int n)
{
    int lo = 0;
    int hi = max(0, n);
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (x <= arr[mid])
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    if (hi <= n - 1 && hi >= 0 && arr[hi] == x)
        cout << "Element Found at : " << hi;
    else
        cout << "Element Not Found" << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    cout << "Before Sorting : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    insertionSort(arr, n);
    cout << "\nAfter Sorting : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int x;
    cout << "\nSearch An Element : " << endl;
    cin >> x;
    binarySearch(x, arr, n);
    return 0;
}