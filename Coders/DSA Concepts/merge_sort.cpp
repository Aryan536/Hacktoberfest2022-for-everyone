#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - p;
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++)
        a1[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        a2[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
        cnt++;
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
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
    cout << "Before Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "No Of steps: " << cnt << endl;
    return 0;
}