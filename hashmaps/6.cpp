#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> values;
    unordered_map<int, int> freq_map;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int value, complement;
        cin >> value;
        values.push_back(value);
        complement = k - value;

        int two_sum = 0;
        for (int j = 0; j < i; j++)
        {
            int two_sum_complement = complement - values[j];

            if (values[j] == two_sum_complement)
            {
                // combinations of two: one + itself
                two_sum += freq_map[values[j]] - 1;
            }
            else if (freq_map.find(two_sum_complement) != freq_map.end())
            {
                two_sum += freq_map[two_sum_complement];
            }
        }
        ans += two_sum / 2;

        freq_map.find(value) != freq_map.end() ? freq_map[value]++
                                               : freq_map[value] = 1;
    }

    cout << ans << '\n';

    return 0;
}
