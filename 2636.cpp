#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n_row, n_col;
vector<vector<int>> board;

bool in_range(int y, int x)
{
    return (y >= 0 && y < n_row && x >= 0 && x < n_col);
}

int bfs(int y, int x)
{
    int n_melted = 0;
    queue<pair<int, int>> q;
    vector<int> visited(n_row * n_col);
    q.push({y, x});
    visited[y * n_col + x] = 1;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (auto move : moves)
        {
            int _y = t.first + move[0], _x = t.second + move[1];
            if (in_range(_y, _x) && !visited[_y * n_col + _x])
            {
                if (board[_y][_x])
                {
                    board[_y][_x] = 0;
                    n_melted++;
                    visited[_y * n_col + _x] = 1;
                }
                else
                {
                    q.push({_y, _x});
                    visited[_y * n_col + _x] = 1;
                }
            }
        }
    }

    return n_melted;
}

int main()
{
    cin >> n_row >> n_col;
    board.resize(n_row);

    for (int y = 0; y < n_row; y++)
        for (int x = 0; x < n_col; x++)
        {
            char t;
            cin >> t;
            board[y].push_back(t - '0');
        }

    int duration = 0, n_remaining;
    while (true)
    {
        int n_melted = bfs(0, 0);

        if (!n_melted)
            break;
        else
        {
            n_remaining = n_melted;
            duration++;
        }
    }

    cout << duration << '\n' << n_remaining << '\n';

    return 0;
}
