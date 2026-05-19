#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 875714 + 1;

// used global vars because large arrays on stack can crash the prog
vector<int> adj[MAXN];
vector<int> rev_adj[MAXN];
bool visited[MAXN];
vector<int> finish_order;
vector<int> scc_sizes;

void first_pass_dfs(int start_node)
{
    stack<pair<int, int>> s;
    s.push({start_node, 0});
    visited[start_node] = true;

    while (!s.empty())
    {
        int u = s.top().first;
        int &neighbor_idx = s.top().second;

        if (neighbor_idx < rev_adj[u].size())
        {
            int v = rev_adj[u][neighbor_idx];
            neighbor_idx++;
            if (!visited[v])
            {
                visited[v] = true;
                s.push({v, 0});
            }
        }
        else
        {
            finish_order.push_back(u);
            s.pop();
        }
    }
}

void second_pass_dfs(int start_node)
{
    stack<int> s;
    s.push(start_node);
    visited[start_node] = true;
    int size = 0;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        size++;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    scc_sizes.push_back(size);
}

void kosaraju()
{
    for (int i = MAXN - 1; i >= 1; i--)
        if ((!rev_adj[i].empty() || !adj[i].empty()) && !visited[i])
            first_pass_dfs(i);

    for (int i = 0; i < MAXN; i++)
    {
        rev_adj[i].clear();
        rev_adj[i].shrink_to_fit();
        visited[i] = false;
    }

    for (int i = finish_order.size() - 1; i >= 0; i--)
    {
        int node = finish_order[i];
        if (!visited[node])
            second_pass_dfs(node);
    }

    sort(scc_sizes.rbegin(), scc_sizes.rend());

    for (int i = 0; i < 5; i++)
    {
        if (i < scc_sizes.size())
            cout << scc_sizes[i];
        else
            cout << "0";
        if (i < 4)
            cout << ",";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file("scc.txt");

    int u, v;
    while (file >> u >> v)
    {
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    file.close();

    kosaraju();

    return 0;
}
