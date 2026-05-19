#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long total_comparisons = 0;

int get_median_index(vector<int> &arr, int l, int r)
{
    int mid = l + (r - l) / 2;

    int left_val = arr[l];
    int right_val = arr[r];
    int mid_val = arr[mid];

    if ((mid_val >= left_val && mid_val <= right_val) ||
        (mid_val >= right_val && mid_val <= left_val))
        return mid;
    if ((left_val >= mid_val && left_val <= right_val) ||
        (left_val >= right_val && left_val <= mid_val))
        return l;
    return r;
}

int partition(vector<int> &arr, int l, int r)
{
    int median = get_median_index(arr, l, r);
    swap(arr[l], arr[median]);

    int pivot = arr[l];
    int i = l + 1;
    int j = l + 1;

    while (j <= r)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    swap(arr[l], arr[i - 1]);
    return i - 1;
}

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    total_comparisons += (r - l);

    int pivot_index = partition(arr, l, r);

    quick_sort(arr, l, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, r);
}

int main()
{
    ifstream infile("UnsortedIntegers.txt");
    vector<int> data;
    int val;
    while (infile >> val)
        data.push_back(val);

    if (!data.empty())
        quick_sort(data, 0, data.size() - 1);

    cout << "Total comparisons: " << total_comparisons << endl;

    return 0;
}
