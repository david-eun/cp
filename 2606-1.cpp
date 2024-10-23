#include <iostream>
#include <vector>

using namespace std;

// Implementation of DFS using recurision
int dfs(const vector<vector<int>> &network, int n)
{
    static int count = 0;
    static vector<int> visited(network.size());

    visited[n] = 1;
    count++;
    for (int i : network[n])
    {
        if (!visited[i])
            dfs(network, i);
    }

    // Exclude itself
    return count - 1;
}

int main()
{
    int n_comp, n_conn;
    cin >> n_comp >> n_conn;

    vector<vector<int>> network(n_comp);

    for (int i = 0; i < n_conn; i++)
    {
        int comp_a, comp_b;
        cin >> comp_a >> comp_b;

        network[comp_a - 1].push_back(comp_b - 1);
        network[comp_b - 1].push_back(comp_a - 1);
    }

    cout << dfs(network, 0) << '\n';

    return 0;
}
