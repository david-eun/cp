#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> freq_map;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        freq_map.find(value) != freq_map.end() ? freq_map[value]++
                                               : freq_map[value] = 1;
    }

    int x, ans = 0;
    cin >> x;

    for (auto i : freq_map)
    {
        int value = i.first, complement = x - value;

        if (value == complement)
        {
            // number of combinations of two
            ans += i.second * (i.second - 1) / 2;
        }
        else if (value > complement &&
                 freq_map.find(complement) != freq_map.end())
        {
            ans += i.second * freq_map[complement];
        }
    }

    cout << ans << '\n';

    return 0;
}
