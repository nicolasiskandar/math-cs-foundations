#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

struct City
{
    int id;
    double x, y;
};

double squared_dist(const City &a, const City &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
    std::ifstream infile("nn.txt");

    int num_cities;
    infile >> num_cities;

    std::vector<City> cities(num_cities);
    for (int i = 0; i < num_cities; ++i)
        infile >> cities[i].id >> cities[i].x >> cities[i].y;
    infile.close();

    std::vector<bool> visited(num_cities, false);
    double total_distance = 0.0;
    int current_idx = 0;
    visited[0] = true;
    int visited_count = 1;

    while (visited_count < num_cities)
    {
        int next_city = -1;
        double min_sq_dist = std::numeric_limits<double>::max();

        for (int i = 0; i < num_cities; ++i)
        {
            if (!visited[i])
            {
                double d_sq = squared_dist(cities[current_idx], cities[i]);

                if (d_sq < min_sq_dist)
                {
                    min_sq_dist = d_sq;
                    next_city = i;
                }
            }
        }

        total_distance += std::sqrt(min_sq_dist);
        visited[next_city] = true;
        current_idx = next_city;
        visited_count++;
    }

    total_distance += std::sqrt(squared_dist(cities[current_idx], cities[0]));

    std::cout << (long long)std::floor(total_distance) << std::endl;

    return 0;
}
