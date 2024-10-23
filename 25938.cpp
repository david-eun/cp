#include <iostream>

using namespace std;

int main()
{
    int g;
    cin >> g;

    for (int i = 1; i <= g; i++)
    {
        int d, n;
        cin >> d >> n;

        cout << "Grid #" << i << ": ";

        if ((n - 1) * (n - 1) >= d - 1)
            cout << (n - 1) * 2 * d;
        else
            cout << "impossible";

        cout << "\n\n";
    }

    return 0;
}
