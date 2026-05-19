#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TwoSat
{
    int n;
    vector<vector<int>> adj, rev_adj;

    TwoSat(int num_vars) : n(num_vars)
    {
        adj.resize(2 * n);
        rev_adj.resize(2 * n);
    }

    inline int get_node(int lit)
    {
        return (lit > 0) ? 2 * (lit - 1) : 2 * (-lit - 1) + 1;
    }

    inline int get_neg(int node) { return node ^ 1; }

    void add_clause(int u_lit, int v_lit)
    {
        int u = get_node(u_lit);
        int v = get_node(v_lit);
        adj[get_neg(u)].push_back(v);
        adj[get_neg(v)].push_back(u);
        rev_adj[v].push_back(get_neg(u));
        rev_adj[u].push_back(get_neg(v));
    }

    bool check_satisfiability()
    {
        int num_nodes = 2 * n;
        vector<int> order;
        vector<bool> visited(num_nodes, false);

        for (int i = 0; i < num_nodes; ++i)
        {
            if (visited[i])
                continue;
            stack<pair<int, int>> s;
            s.push({i, 0});
            visited[i] = true;
            while (!s.empty())
            {
                int u = s.top().first;
                int &child_idx = s.top().second;
                if (child_idx < adj[u].size())
                {
                    int v = adj[u][child_idx++];
                    if (!visited[v])
                    {
                        visited[v] = true;
                        s.push({v, 0});
                    }
                }
                else
                {
                    order.push_back(u);
                    s.pop();
                }
            }
        }

        vector<int> component(num_nodes, -1);
        int component_count = 0;
        for (int i = num_nodes - 1; i >= 0; --i)
        {
            int root = order[i];
            if (component[root] != -1)
                continue;

            stack<int> s;
            s.push(root);
            component[root] = component_count;
            while (!s.empty())
            {
                int u = s.top();
                s.pop();
                for (int v : rev_adj[u])
                {
                    if (component[v] == -1)
                    {
                        component[v] = component_count;
                        s.push(v);
                    }
                }
            }
            component_count++;
        }

        for (int i = 0; i < n; ++i)
            if (component[2 * i] == component[2 * i + 1])
                return false;
        return true;
    }
};

int main()
{
    string files[] = {"2sat1.txt", "2sat2.txt", "2sat3.txt",
                      "2sat4.txt", "2sat5.txt", "2sat6.txt"};
    string result_bits = "";

    for (const string &fname : files)
    {
        ifstream infile(fname);

        int num_vars;
        infile >> num_vars;
        TwoSat solver(num_vars);

        int u, v;
        while (infile >> u >> v)
            solver.add_clause(u, v);

        result_bits += (solver.check_satisfiability() ? "1" : "0");
    }

    cout << result_bits << endl;
    return 0;
}
