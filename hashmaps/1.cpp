#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        string action;
        cin >> action;

        int k, v;
        if (action == "add")
        {
            cin >> k >> v;
            m[k] = v;
        }
        else if (action == "remove")
        {
            cin >> k;
            m.erase(k);
        }
        else if (action == "find")
        {
            cin >> k;
            if (m.find(k) != m.end())
            {
                cout << m[k] << '\n';
            }
            else
            {
                cout << "None\n";
            }
        }
    }

    return 0;
}
