#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> ropes;
    for (int i = 0; i < n; i++)
    {
        int rope;
        cin >> rope;
        ropes.push_back(rope);
    }

    sort(ropes.begin(), ropes.end(), greater<int>());

    int max_weight = 0;
    for (int i = 0; i < n; i++)
    {
        if (max_weight < ropes[i] * (i + 1))
            max_weight = ropes[i] * (i + 1);
    }

    cout << max_weight << '\n';

    return 0;
}
