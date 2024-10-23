#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq_map;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int value, complement;
        cin >> value;
        complement = k - value;

        freq_map.find(value) != freq_map.end() ? freq_map[value]++
                                               : freq_map[value] = 1;

        if (value == complement)
        {
            ans += freq_map[value] - 1; // combinations of two: one + itself
        }
        else if (freq_map.find(complement) != freq_map.end())
        {
            ans += freq_map[complement];
        }
    }

    cout << ans << '\n';

    return 0;
}
