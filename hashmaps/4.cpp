#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // keys and values are all strings, as the type of the test case isn't known
    unordered_map<string, string> map;

    for (int i = 0; i < n; i++)
    {
        string value;
        cin >> value;

        map[value] = to_string(i + 1);
        map[to_string(i + 1)] = value;
    }

    for (int i = 0; i < m; i++)
    {
        string value;
        cin >> value;

        cout << map[value] << '\n';
    }

    return 0;
}
