#include <iostream>
#include <vector>
using namespace std;

int partition(vector<long long> &arr, int low, int high)
{
    long long pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<long long> &arr, int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr,0,n-1);

    cout<<"Sorted Array : ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    cout<<"Top 5 : ";

    long long sumTop = 0;

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
        sumTop += arr[i];
    }

    cout<<endl;

    double topAverage = sumTop / 5.0;

    cout<<"Average of Top 5 : "<<topAverage<<endl;

    long long total = 0;

    for(int i=0;i<n;i++)
        total += arr[i];

    double overallAverage = total * 1.0 / n;

    int count = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > overallAverage)
            count++;
    }

    cout<<"Values Above Overall Average : "<<count;

    return 0;
}