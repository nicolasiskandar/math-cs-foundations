#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;

    long long median_sum = 0;
    int x;

    ifstream file("Median.txt");

    while (file >> x)
    {
        if (low.empty() || x <= low.top())
            low.push(x);
        else
            high.push(x);

        if (low.size() > high.size() + 1)
        {
            high.push(low.top());
            low.pop();
        }
        else if (high.size() > low.size())
        {
            low.push(high.top());
            high.pop();
        }

        median_sum += low.top();
    }

    cout << median_sum % 10'000 << endl;

    return 0;
}
