#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> freq_map;
    int max_freq = 0;

    for (int i = 0; i < n; i++)
    {
        string value;
        cin >> value;

        if (freq_map.find(value) != freq_map.end())
        {
            if (++freq_map[value] > max_freq)
            {
                max_freq = freq_map[value];
            }
        }
        else
        {
            freq_map[value] = 1;
            if (!max_freq)
                max_freq = 1;
        }
    }

    cout << max_freq << '\n';

    return 0;
}
