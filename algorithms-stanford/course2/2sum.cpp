#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

int main()
{
    std::ifstream file("2sum_integers.txt");
    std::vector<long long> nums;
    long long val;

    while (file >> val)
        nums.push_back(val);
    std::sort(nums.begin(), nums.end());

    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    std::unordered_set<long long> found_targets;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        long long x = nums[i];
        long long low_y = -10'000 - x;
        long long high_y = 10'000 - x;

        auto it_start = std::lower_bound(nums.begin(), nums.end(), low_y);

        for (auto it = it_start; it != nums.end() && *it <= high_y; ++it)
            if (*it != x)
                found_targets.insert(x + *it);
    }

    std::cout << found_targets.size() << std::endl;

    return 0;
}
