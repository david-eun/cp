#include <iostream>
#include <string>

using namespace std;

string gears[4] = {};
int g_pos[4] = {0};

int mod8(int n) { return ((n % 8) + 8) % 8; }

void g_spin(int g_num, int direction)
{
    int directions[4] = {0};
    directions[g_num] = direction;

    // check gears to the left
    for (int g = g_num; g > 0; g--)
    {
        if (gears[g][mod8(g_pos[g] - 2)] !=
            gears[g - 1][mod8(g_pos[g - 1] + 2)])
        {
            directions[g - 1] = directions[g] * -1;
        }
        else
            break;
    }

    // check gears to the right
    for (int g = g_num; g < 3; g++)
    {
        if (gears[g][mod8(g_pos[g] + 2)] !=
            gears[g + 1][mod8(g_pos[g + 1] - 2)])
        {
            directions[g + 1] = directions[g] * -1;
        }
        else
            break;
    }

    for (int i = 0; i < 4; i++)
    {
        g_pos[i] += directions[i];
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> gears[i];
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int g_num, direction;
        cin >> g_num >> direction;
        g_spin(g_num - 1, direction * -1);
    }

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans += (gears[i][mod8(g_pos[i])] - '0') << i;
    }

    cout << ans << '\n';

    return 0;
}
