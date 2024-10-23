#include <iostream>
#include <queue>

using namespace std;

int abs(int value) { return value < 0 ? -value : value; }

struct comp_abs_less
{
    bool operator()(int lhs, int rhs)
    {
        if (abs(lhs) == abs(rhs))
        {
            return lhs > rhs;
        }
        return abs(lhs) > abs(rhs);
    }
};

int main()
{
    int n_cases;
    cin >> n_cases;

    priority_queue<int, vector<int>, comp_abs_less> priority_queue;

    for (int i = 0; i < n_cases; i++)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            if (priority_queue.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << priority_queue.top() << '\n';
                priority_queue.pop();
            }
        }
        else
        {
            priority_queue.push(n);
        }
    }
}
