#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const float INF = 1e18;

struct City
{
    float x, y;
};

float calculate_dist(const City &a, const City &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    ifstream infile("tsp.txt");

    int n;
    infile >> n;

    vector<City> cities(n);
    for (int i = 0; i < n; ++i)
        infile >> cities[i].x >> cities[i].y;
    infile.close();

    vector<vector<float>> dist(n, vector<float>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = calculate_dist(cities[i], cities[j]);

    int num_masks = 1 << n;
    vector<vector<float>> dp(num_masks, vector<float>(n, INF));

    dp[1][0] = 0;

    for (int mask = 1; mask < num_masks; ++mask)
    {
        if (!(mask & 1))
            continue;

        for (int i = 0; i < n; ++i)
        {
            if (!(mask & (1 << i)))
                continue;
            if (dp[mask][i] == INF)
                continue;

            for (int j = 0; j < n; ++j)
            {
                if (!(mask & (1 << j)))
                {
                    int next_mask = mask | (1 << j);
                    float new_dist = dp[mask][i] + dist[i][j];
                    if (new_dist < dp[next_mask][j])
                        dp[next_mask][j] = new_dist;
                }
            }
        }
    }

    float min_tour = INF;
    int full_mask = (1 << n) - 1;
    for (int i = 1; i < n; ++i)
        min_tour = min(min_tour, dp[full_mask][i] + dist[i][0]);

    cout << "Rounded down: " << (long long)floor(min_tour) << endl;

    return 0;
}
