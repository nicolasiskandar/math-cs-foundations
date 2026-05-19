#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream file("mwis.txt");

    int n;
    file >> n;

    vector<long long> w(n + 1);
    for (int i = 1; i <= n; i++)
        file >> w[i];

    vector<long long> A(n + 1);
    A[0] = 0;
    A[1] = w[1];

    for (int i = 2; i <= n; i++)
        A[i] = max(A[i - 1], A[i - 2] + w[i]);

    vector<bool> inMWIS(n + 1, false);

    int i = n;
    while (i >= 1)
    {
        if (i == 1)
        {
            if (A[i] > 0)
                inMWIS[i] = true;
            break;
        }

        if (A[i - 1] >= A[i - 2] + w[i])
            i = i - 1;
        else
        {
            inMWIS[i] = true;
            i = i - 2;
        }
    }

    vector<int> query = {1, 2, 3, 4, 17, 117, 517, 997};

    for (int v : query)
    {
        if (v <= n && inMWIS[v])
            cout << "1";
        else
            cout << "0";
    }

    cout << endl;

    return 0;
}
