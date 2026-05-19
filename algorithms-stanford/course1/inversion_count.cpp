#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long merge_and_count(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArr, rightArr;
    for (int i = left; i <= mid; i++)
        leftArr.push_back(arr[i]);
    for (int i = mid + 1; i <= right; i++)
        rightArr.push_back(arr[i]);

    long long count = 0;
    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
        {
            arr[k++] = rightArr[j++];
            count += (leftArr.size() - i);
        }
    }

    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];

    return count;
}

long long count_inversions(vector<int> &arr, int left, int right)
{
    long long count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        count += count_inversions(arr, left, mid);
        count += count_inversions(arr, mid + 1, right);
        count += merge_and_count(arr, left, mid, right);
    }
    return count;
}

int main()
{
    ifstream input_file("IntegerArray.txt");
    vector<int> numbers;
    int val;

    while (input_file >> val)
        numbers.push_back(val);

    cout << "Total Inversions: "
         << count_inversions(numbers, 0, numbers.size() - 1) << "\n";

    return 0;
}
