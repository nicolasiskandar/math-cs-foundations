#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Edge
{
    int u;
    int v;
};

struct DSU
{
    vector<int> parent;
    int num_components;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        num_components = n;
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_i] = root_j;
            num_components--;
        }
    }
};

int karger(int n, const vector<Edge> &edges, mt19937 &rng)
{
    DSU dsu(n);
    vector<Edge> shuffled_edges = edges;
    shuffle(shuffled_edges.begin(), shuffled_edges.end(), rng);

    int i = 0;
    while (dsu.num_components > 2 && i < shuffled_edges.size())
    {
        dsu.unite(shuffled_edges[i].u, shuffled_edges[i].v);
        i++;
    }

    int cut_count = 0;
    for (const auto &edge : edges)
        if (dsu.find(edge.u) != dsu.find(edge.v))
            cut_count++;

    return cut_count;
}

int main()
{
    ifstream infile("kargerMinCut.txt");
    vector<Edge> edges;
    string line;
    int max_v = 0;

    while (getline(infile, line))
    {
        stringstream ss(line);
        int u, v;
        ss >> u;
        max_v = max(max_v, u);
        while (ss >> v)
            if (u < v)
                edges.push_back({u, v});
    }

    mt19937 rng(time(0));
    int min_cut = edges.size();

    int iterations = 10000;
    for (int i = 0; i < iterations; i++)
    {
        int current_cut = karger(max_v, edges, rng);
        if (current_cut < min_cut)
            min_cut = current_cut;
    }

    cout << "The min cut found is: " << min_cut << endl;

    return 0;
}
