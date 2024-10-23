#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct element
{
    bool operator()(element lhs, element rhs)
    {
        return lhs.freq == rhs.freq ? lhs.value < rhs.value
                                    : lhs.freq < rhs.freq;
    }
    int value, freq;
};

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq_map;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        freq_map.find(value) != freq_map.end() ? freq_map[value]++
                                               : freq_map[value] = 1;
    }

    priority_queue<element, vector<element>, element> elements;
    for (auto i : freq_map)
    {
        elements.push({i.first, i.second});
    }

    for (int i = 0; i < k; i++)
    {
        cout << elements.top().value << ' ';
        elements.pop();
    }

    cout << '\n';

    return 0;
}
