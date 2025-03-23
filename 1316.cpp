#include <iostream>
#include <string>

using namespace std;

int main() {
  unsigned n, ans = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    bool is_group_word = true;
    bool chars[26] = {0};
    for (int j = 0; j < s.length(); j++) {
      chars[s[j] - 'a'] = 1;

      if (j + 1 < s.length() && s[j] != s[j + 1]) {
        if (chars[s[j + 1] - 'a']) {
          is_group_word = false;
          break;
        }
      }
    }

    if (is_group_word) {
      ans++;
    }
  }

  cout << ans << '\n';
}
