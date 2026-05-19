#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct UnionFind
{
    vector<int> parent;
    int num_clusters;

    UnionFind(int n) : num_clusters(n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
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
            num_clusters--;
        }
    }
};

int parseBits(const string &line)
{
    int val = 0;
    stringstream ss(line);
    int bit;
    while (ss >> bit)
        val = (val << 1) | bit;
    return val;
}

int main()
{
    ifstream infile("clustering_big.txt");

    int num_nodes, num_bits;
    infile >> num_nodes >> num_bits;
    string line;
    getline(infile, line); 

    unordered_map<int, int> node_to_idx;
    vector<int> unique_nodes;

    for (int i = 0; i < num_nodes; ++i)
    {
        getline(infile, line);
        int val = parseBits(line);
        if (node_to_idx.find(val) == node_to_idx.end())
        {
            node_to_idx[val] = unique_nodes.size();
            unique_nodes.push_back(val);
        }
    }

    int n_unique = unique_nodes.size();
    UnionFind uf(n_unique);

    cout << "Processing " << n_unique << " unique nodes..." << endl;

    for (int i = 0; i < n_unique; ++i)
    {
        int val = unique_nodes[i];

        for (int b1 = 0; b1 < num_bits; ++b1)
        {
            int neighbor = val ^ (1 << b1);
            if (node_to_idx.count(neighbor))
                uf.unite(i, node_to_idx[neighbor]);

            for (int b2 = b1 + 1; b2 < num_bits; ++b2)
            {
                int neighbor2 = neighbor ^ (1 << b2);
                if (node_to_idx.count(neighbor2))
                    uf.unite(i, node_to_idx[neighbor2]);
            }
        }
    }

    cout << uf.num_clusters << endl;

    return 0;
}
