#include <bits/stdc++.h>
using namespace std;
using intl = long long int;
int partition(int lo, int hi, vector<int> &arr)
{
    int i = lo;
    int j = hi;
    int pivot = lo;

    while (i < j)
    {
        while (i <= hi && arr[i] <= arr[pivot])
        {
            i++;
        }
        while (j >= lo && arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);
    return j;
}
int partitionRandom(int lo, int hi, vector<int> &arr)
{
    int i = lo;
    int j = hi;
    int pivot = rand() % (hi - lo) + lo;

    while (i < j)
    {
        while (i <= hi && arr[i] <= arr[pivot])
        {
            i++;
        }
        while (j >= lo && arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);
    return j;
}
void quickSort(int lo, int hi, vector<int> &arr)
{
    if (lo < hi)
    {

        int ind = partitionRandom(lo, hi, arr);
        quickSort(lo, ind - 1, arr);
        quickSort(ind + 1, hi, arr);
    }
}
int main()
{
    vector<int> arr = {12, 3, 4, 2, 1, 56, 8};
    quickSort(0, arr.size() - 1, arr);
    srand(time(0));
    for (auto &x : arr)
        cout << x << " ";

    return 0;
}

/*
TC: O(nlogn) as array is being split into two halves every time
worst case is n^2
With random pivot selection, the likelihood of encountering the worst-case scenario (highly unbalanced partitions : choosing min or max as the pivot) is reduced       
SC: O(1)
*/