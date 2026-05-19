#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, cost;
};

bool compareEdges(const Edge &a, const Edge &b) { return a.cost < b.cost; }

struct DSU
{
    vector<int> parent;
    int num_clusters;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        num_clusters = n;
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_i] = root_j;
            num_clusters--;
            return true;
        }
        return false;
    }
};

int main()
{
    ifstream infile("clustering1.txt");

    int n;
    infile >> n;

    vector<Edge> edges;
    int u, v, cost;
    while (infile >> u >> v >> cost)
        edges.push_back({u, v, cost});

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(n);
    int k = 4;

    size_t i = 0;
    while (dsu.num_clusters > k && i < edges.size())
    {
        dsu.unite(edges[i].u, edges[i].v);
        i++;
    }

    for (; i < edges.size(); ++i)
        if (dsu.find(edges[i].u) != dsu.find(edges[i].v))
        {
            cout << edges[i].cost << endl;
            break;
        }

    return 0;
}
