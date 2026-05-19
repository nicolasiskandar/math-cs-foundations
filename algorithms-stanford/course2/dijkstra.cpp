#include <climits>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int UNREACHABLE = 1'000'000;

struct Edge
{
    int to;
    int weight;
};

struct Node
{
    int id;
    int dist;
    bool operator>(const Node &other) const { return dist > other.dist; }
};

void run_dijkstra(int source, int num_vertices, const vector<vector<Edge>> &adj)
{
    vector<int> distances(num_vertices + 1, UNREACHABLE);
    distances[source] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({source, 0});

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        int u = current.id;
        int d = current.dist;

        if (d > distances[u])
            continue;

        for (const auto &edge : adj[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                pq.push({v, distances[v]});
            }
        }
    }

    vector<int> targets = {7, 37, 59, 82, 99, 115, 133, 165, 188, 197};

    for (size_t i = 0; i < targets.size(); ++i)
        cout << distances[targets[i]] << (i == targets.size() - 1 ? "" : ",");
    cout << endl;
}

int main()
{
    ifstream infile("dijkstraData.txt");

    vector<vector<Edge>> adj(201);
    string line;

    while (getline(infile, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        int u;
        ss >> u;

        string neighborData;
        while (ss >> neighborData)
        {
            size_t commaPos = neighborData.find(',');
            if (commaPos != string::npos)
            {
                int v = stoi(neighborData.substr(0, commaPos));
                int weight = stoi(neighborData.substr(commaPos + 1));
                adj[u].push_back({v, weight});
            }
        }
    }

    run_dijkstra(1, 200, adj);

    return 0;
}
