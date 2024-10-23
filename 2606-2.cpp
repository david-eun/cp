#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Implementation of DFS using a stack
int dfs(const vector<vector<int>> &network, int n)
{
    int count = 0;
    stack<int> l;
    vector<int> visited(network.size());

    l.push(n);
    visited[n] = 1;

    while (!l.empty())
    {
        int t = l.top();
        l.pop();

        for (int i : network[t])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                count++;
                l.push(i);
            }
        }
    }

    return count;
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
