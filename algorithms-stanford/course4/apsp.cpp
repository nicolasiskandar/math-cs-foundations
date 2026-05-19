#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int N = 1000;
const long long INF = 1e18;

void readGraph(const string &filename, vector<vector<long long>> &g)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening " << filename << endl;
        return;
    }

    int u, v;
    long long w;
    string line;

    getline(file, line);

    while (getline(file, line))
        if (sscanf(line.c_str(), "%d %d %lld", &u, &v, &w) == 3)
            g[u - 1][v - 1] = w;
    file.close();
}

long long floydWarshall(vector<vector<long long>> &g)
{
    vector<vector<long long>> dist = g;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            if (dist[i][k] != INF)
                for (int j = 0; j < N; j++)
                    if (dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < N; i++)
        if (dist[i][i] < 0)
        {
            cerr << "Negative cycle detected!" << endl;
            return -INF;
        }

    long long minDist = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (dist[i][j] != INF && i != j)
                minDist = min(minDist, dist[i][j]);

    return minDist;
}

int main()
{
    vector<string> files = {"g1.txt", "g2.txt", "g3.txt"};

    for (const auto &file : files)
    {
        vector<vector<long long>> g(N, vector<long long>(N, INF));
        for (int i = 0; i < N; i++)
            g[i][i] = 0;

        readGraph(file, g);

        long long minDist = floydWarshall(g);
        cout << file << " min distance = " << minDist << endl;
    }

    return 0;
}