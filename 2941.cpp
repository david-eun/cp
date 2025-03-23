#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  unsigned i = 0, num_char = 0;
  while (i < s.length()) {
    // Prevent indexing out of range
    if (i + 2 < s.length()) {
      if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
        num_char++, i += 3;
        continue;
      }
    }

    if (i + 1 < s.length()) {
      if ((s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) ||
          (s[i] == 'd' && s[i + 1] == '-') ||
          ((s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j') ||
          ((s[i] == 's' || s[i] == 'z') && s[i + 1] == '=')) {
        num_char++, i += 2;
        continue;
      }
    }

    num_char++, i++;
  }

  cout << num_char << '\n';

  return 0;
}
