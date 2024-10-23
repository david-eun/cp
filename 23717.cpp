#include <iostream>
#include <string>

using namespace std;

int count_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int color_to_int(char color)
{
    // R: 1, Y: 2, B: 4
    switch (color)
    {
        case 'R':
            return 1;
        case 'Y':
            return 2;
        case 'O':
            return 3;
        case 'B':
            return 4;
        case 'P':
            return 5;
        case 'G':
            return 6;
        case 'A':
            return 7;
        default:
            return 0;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        string p;
        cin >> p;

        int n_strokes = 0;
        int prev_color = 0, curr_color;
        for (char color : p)
        {
            curr_color = color_to_int(color);

            n_strokes += count_set_bits(~curr_color & prev_color);

            prev_color = curr_color;
        }
        n_strokes += count_set_bits(curr_color);

        cout << "Case #" << i + 1 << ": " << n_strokes << '\n';
    }

    return 0;
}
