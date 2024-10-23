#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> freq_map;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (freq_map.find(value) != freq_map.end())
        {
            freq_map[value] += 1;
        }
        else
        {
            freq_map[value] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;

        if (freq_map.find(value) != freq_map.end())
        {
            cout << freq_map[value] << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }

    return 0;
}
