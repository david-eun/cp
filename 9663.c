#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int queens[14];
int cnt = 0;

bool queen_placed[14] = {0};

void cnt_queen_placement(int d) {
  if (d == n) {
    cnt++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!queen_placed[i]) {
      bool can_place = true;
      for (int j = 0; j < d; j++) {
        if (abs(queens[j] - i) == d - j) {
          can_place = false;
          break;
        }
      }

      if (can_place) {
        queen_placed[i] = true;
        queens[d] = i;
        cnt_queen_placement(d + 1);
        queen_placed[i] = false;
      }
    }
  }
}

int main(void) {
  scanf("%d", &n);
  cnt_queen_placement(0);
  printf("%d\n", cnt);

  return 0;
}
