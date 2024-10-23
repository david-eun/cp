#include <iostream>
#include <string>
#include <vector>

using namespace std;

int r, c;
int visited_c[26] = {0};
vector<string> board;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int y, int x)
{
    int d = 0;
    visited_c[board[y][x] - 'A'] = 1;

    for (int* move : moves)
    {
        int _y = y + move[0], _x = x + move[1];
        if ((_y >= 0 && _y < r && _x >= 0 && _x < c) &&
            !visited_c[board[_y][_x] - 'A'])
        {
            int _d = dfs(_y, _x);
            if (_d > d)
            {
                d = _d;
            }
        }
    }

    visited_c[board[y][x] - 'A'] = 0;

    return d + 1; // include (x, y)
}

int main()
{
    cin >> r >> c;

    for (int y = 0; y < r; y++)
    {
        string row;
        cin >> row;
        board.push_back(row);
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}
