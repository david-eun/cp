#include <stdbool.h>
#include <stdio.h>

int board[9][9];
int empty[81];
int empty_n = 0;
bool finish = false;

bool check(int y, int x, int v) {
  for (int i = 0; i < 9; i++) {
    if ((v == board[y][i] && i != x) || (v == board[i][x] && i != y)) {
      return false;
    }
  }

  int bx = (x / 3) * 3, by = (y / 3) * 3;
  for (int i = by; i < by + 3; i++) {
    for (int j = bx; j < bx + 3; j++) {
      if (v == board[i][j] && (y != i || x != j)) {
        return false;
      }
    }
  }

  return true;
}

void solve(int n) {
  if (n == empty_n) {
    finish = true;
    return;
  }

  int r = empty[n] / 9, c = empty[n] % 9;
  for (int i = 1; i <= 9; i++) {
    if (check(r, c, i)) {
      board[r][c] = i;
      solve(n + 1);
    }

    if (finish) {
      return;
    }
  }

  board[r][c] = 0;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &board[i][j]);
      if (!board[i][j]) {
        empty[empty_n++] = i * 9 + j;
      }
    }
  }

  solve(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
