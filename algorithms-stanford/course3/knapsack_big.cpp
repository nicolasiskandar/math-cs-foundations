#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Item
{
    int value;
    int weight;
};

unordered_map<long long, long long> memo;

long long solve(int i, int w, const vector<Item> &items)
{
    if (i < 0 || w <= 0)
        return 0;

    long long key = ((long long)i << 32) | w;

    if (memo.count(key))
        return memo[key];

    long long res = solve(i - 1, w, items);

    if (items[i].weight <= w)
        res = max(res, (long long)items[i].value +
                           solve(i - 1, w - items[i].weight, items));

    return memo[key] = res;
}

int main()
{
    ifstream infile("knapsack_big.txt");

    int capacity, num_items;
    infile >> capacity >> num_items;

    vector<Item> items(num_items);
    for (int i = 0; i < num_items; ++i)
        infile >> items[i].value >> items[i].weight;

    cout << solve(num_items - 1, capacity, items) << endl;

    infile.close();
    return 0;
}
