#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream infile("knapsack1.txt");

    int capacity, num_items;
    infile >> capacity >> num_items;

    vector<long long> dp(capacity + 1, 0);

    for (int i = 0; i < num_items; ++i)
    {
        int value, weight;
        infile >> value >> weight;
        for (int w = capacity; w >= weight; --w)
            dp[w] = max(dp[w], dp[w - weight] + value);
    }

    cout << dp[capacity] << endl;

    infile.close();
    return 0;
}
