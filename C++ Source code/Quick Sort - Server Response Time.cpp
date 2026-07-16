#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = low; k <= high; k++)
    {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if(low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array : ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    int median = arr[n / 2];

    cout << "Median : " << median << endl;

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > median)
            count++;
    }

    cout << "Orders Above Median : " << count << endl;

    int diff = arr[n - 1] - arr[0];

    cout << "Difference : " << diff;

    return 0;
}
