#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> deque;
    for (int i = 0; i < n; i++)
    {
        string action;
        cin >> action;

        if (action == "push_front")
        {
            int value;
            cin >> value;

            deque.insert(deque.begin(), value);
        }
        else if (action == "push_back")
        {
            int value;
            cin >> value;

            deque.push_back(value);
        }
        else if (action == "pop_front")
        {
            cout << deque[0] << '\n';
            deque.erase(deque.begin());
        }
        else if (action == "pop_back")
        {
            cout << deque[deque.size() - 1] << '\n';
            deque.pop_back();
        }
    }

    return 0;
}
