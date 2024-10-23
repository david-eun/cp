// Is this problem even possible to solve efficiently using DFS?

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int m, n;
int n_no = 0, n_ripe = 0;
int total_days = 0;
vector<vector<int>> tomatoes;
queue<pair<int, int>> q;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void calc_days()
{
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int* move : moves)
        {
            int _y = t.first + move[0], _x = t.second + move[1];
            if ((_y >= 0 && _y < n && _x >= 0 && _x < m) && !tomatoes[_y][_x])
            {
                tomatoes[_y][_x] = tomatoes[t.first][t.second] + 1;
                q.push({_y, _x});
                n_ripe++;

                if (total_days < tomatoes[_y][_x] - 1)
                    total_days = tomatoes[_y][_x] - 1;
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    tomatoes.resize(n, vector<int>(m));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            int tomato;
            cin >> tomato;
            tomatoes[y][x] = tomato;

            if (tomato == 1)
            {
                q.push({y, x});
                n_ripe++;
            }
            else if (tomato == -1)
            {
                n_no++;
            }
        }
    }

    calc_days();
    cout << ((n_ripe + n_no == m * n) ? total_days : -1) << '\n';

    return 0;
}
