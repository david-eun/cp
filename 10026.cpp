#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(const vector<string>& painting, vector<int>& visited, int y, int x)
{
    int painting_size = painting.size();
    vector<int> stack;
    stack.push_back(y * painting_size + x);
    visited[y * painting_size + x] = 1;

    while (!stack.empty())
    {
        int t = stack.back();
        stack.pop_back();

        int _y = t / painting_size, _x = t % painting_size;

        for (int* move : moves)
        {
            if (_y + move[0] >= 0 && _y + move[0] < painting_size &&
                _x + move[1] >= 0 && _x + move[1] < painting_size)
            {
                int i = (_y + move[0]) * painting_size + (_x + move[1]);
                if (!visited[i] &&
                    painting[_y][_x] == painting[_y + move[0]][_x + move[1]])
                {
                    visited[i] = 1;
                    stack.push_back(i);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> painting, painting_b;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;

        painting.push_back(row);

        replace(row.begin(), row.end(), 'G', 'R');
        painting_b.push_back(row);
    }

    int n_areas = 0, n_areas_b = 0;

    {
        vector<int> visited(n * n);
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                if (!visited[y * n + x])
                {
                    dfs(painting, visited, y, x);
                    n_areas++;
                }
    }

    {
        vector<int> visited(n * n);
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                if (!visited[y * n + x])
                {
                    dfs(painting_b, visited, y, x);
                    n_areas_b++;
                }
    }

    cout << n_areas << ' ' << n_areas_b << '\n';

    return 0;
}
