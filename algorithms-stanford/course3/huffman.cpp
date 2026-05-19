#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    long long weight;
    Node *left;
    Node *right;

    Node(long long w) : weight(w), left(nullptr), right(nullptr) {}
};

struct Compare
{
    bool operator()(Node *a, Node *b) { return a->weight > b->weight; }
};

int get_max_depth(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 0;

    return 1 + max(get_max_depth(root->left), get_max_depth(root->right));
}

int get_min_depth(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 0;

    if (!root->left)
        return 1 + get_min_depth(root->right);

    if (!root->right)
        return 1 + get_min_depth(root->left);

    return 1 + min(get_min_depth(root->left), get_min_depth(root->right));
}

int main()
{
    ifstream file("huffman.txt");
    int n;
    file >> n;

    priority_queue<Node *, vector<Node *>, Compare> min_heap;

    for (int i = 0; i < n; ++i)
    {
        long long weight;
        file >> weight;
        min_heap.push(new Node(weight));
    }

    while (min_heap.size() > 1)
    {
        Node *left = min_heap.top();
        min_heap.pop();
        Node *right = min_heap.top();
        min_heap.pop();

        Node *merged = new Node(left->weight + right->weight);
        merged->left = left;
        merged->right = right;

        min_heap.push(merged);
    }

    Node *root = min_heap.top();

    int max_length = get_max_depth(root);
    cout << max_length << endl;

    int min_depth = get_min_depth(root);
    cout << min_depth << endl;

    return 0;
}
