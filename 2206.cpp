#include <iostream>
#include <queue>

using namespace std;

typedef struct position
{
    int y, x;
    bool used_pass;
} position;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

// 2 maps for traversals with passes and without
int map[1000][1000][2];

int bfs(int y, int x)
{
    queue<position> q;
    q.push({y, x, false});
    map[y][x][false] = 1;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        if (t.y == n - 1 && t.x == m - 1)
            return map[n - 1][m - 1][t.used_pass];

        for (int* move : moves)
        {
            int _y = t.y + move[0], _x = t.x + move[1];
            if (_y >= 0 && _y < n && _x >= 0 && _x < m)
            {
                if (map[_y][_x][0] != -1 && !map[_y][_x][t.used_pass])
                {
                    q.push({_y, _x, t.used_pass});
                    map[_y][_x][t.used_pass] = map[t.y][t.x][t.used_pass] + 1;
                }
                else if (map[_y][_x][0] == -1 && !t.used_pass)
                {
                    q.push({_y, _x, true});
                    map[_y][_x][1] = map[t.y][t.x][0] + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            char t;
            cin >> t;

            if (t == '1')
                map[y][x][0] = -1;
            else
                map[y][x][0] = 0;
        }

    cout << bfs(0, 0) << '\n';

    return 0;
}
