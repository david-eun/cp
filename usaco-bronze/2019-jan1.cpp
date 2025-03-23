#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  freopen("shell.in", "r", stdin);

  int n;
  cin >> n;

  unsigned int shells[3] = {0};

  for (int i = 0; i < n; i++) {
    int a, b, g;
    cin >> a >> b >> g;
    a--, b--, g--;

    swap(shells[a], shells[b]);
    shells[g]++;
  }

  freopen("shell.out", "w", stdout);
  cout << *max_element(shells, shells + 3) << endl;
}
