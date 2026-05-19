#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using Edge = std::pair<int, long long>;   // (neighbor, cost)
using PQNode = std::pair<long long, int>; // (cost, vertex)

std::vector<std::vector<Edge>> read_graph_from_file(const std::string &filename,
                                                    int &n, int &m)
{
    std::ifstream file(filename);

    file >> n >> m;

    std::vector<std::vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long cost;
        file >> u >> v >> cost;

        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    file.close();
    return graph;
}

long long prim_mst(const std::vector<std::vector<Edge>> &graph, int n)
{
    std::vector<bool> visited(n + 1, false);
    std::priority_queue<PQNode, std::vector<PQNode>, std::greater<PQNode>> pq;

    long long total_cost = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        total_cost += cost;

        for (const auto &[neighbor, edge_cost] : graph[node])
            if (!visited[neighbor])
                pq.push({edge_cost, neighbor});
    }

    return total_cost;
}

int main()
{
    int n, m;
    auto graph = read_graph_from_file("edges.txt", n, m);

    std::cout << prim_mst(graph, n) << std::endl;

    return 0;
}
