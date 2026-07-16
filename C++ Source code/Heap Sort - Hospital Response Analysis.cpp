#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    heapSort(arr,n);

    cout<<"Sorted Array : ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    cout<<"Fastest : "<<arr[0]<<endl;

    cout<<"Slowest : "<<arr[n-1]<<endl;

    double sum = 0;

    for(int i=0;i<n;i++)
        sum += arr[i];

    double average = sum / n;

    cout<<fixed<<setprecision(2);
    cout<<"Average : "<<average<<endl;

    int count = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] < average)
            count++;
    }

    cout<<"Cases Faster Than Average : "<<count<<endl;

    double percentage = (count * 100.0) / n;

    cout<<"Percentage : "<<percentage<<"%";

    return 0;
}
