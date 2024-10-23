#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n_decks, n_actions = 0;
    cin >> n_decks;

    priority_queue<int, vector<int>, std::greater<int> > decks;

    for (int i = 0; i < n_decks; i++)
    {
        int n;
        cin >> n;

        decks.push(n);
    }

    while (decks.size() > 1)
    {
        int deck_a, deck_b;

        deck_a = decks.top();
        decks.pop();

        deck_b = decks.top();
        decks.pop();

        n_actions += deck_a + deck_b;
        decks.push(deck_a + deck_b);
    }

    cout << n_actions << endl;
}
