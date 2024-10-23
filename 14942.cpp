#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> connections;
vector<int> room_depth;

void calc_depth(vector<int>& visited, int pos = 0, int depth = 0)
{
    visited[pos] = 1;
    room_depth[pos] = depth;

    depth++;
    for (auto conn : connections[pos])
        if (!visited[conn.first])
            calc_depth(visited, conn.first, depth);
}

int dfs(int pos, int energy)
{
    int final_pos = pos;
    for (auto conn : connections[pos])
        if (room_depth[conn.first] < room_depth[pos] && energy >= conn.second)
            final_pos = dfs(conn.first, energy - conn.second);

    return final_pos;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ants_energy;
    for (int i = 0; i < n; i++)
    {
        int energy;
        cin >> energy;
        ants_energy.push_back(energy);
    }

    connections.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        connections[a - 1].push_back({b - 1, c});
        connections[b - 1].push_back({a - 1, c});
    }

    room_depth.resize(n);
    vector<int> visited(n);
    calc_depth(visited);

    for (int i = 0; i < n; i++)
    {
        cout << dfs(i, ants_energy[i]) + 1 << '\n';
    }

    return 0;
}
