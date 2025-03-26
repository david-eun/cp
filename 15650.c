#include <stdbool.h>
#include <stdio.h>

int n, m;
int seq[8];

void print_all_seq(int d, int p) {
  if (d == m) {
    for (int i = 0; i < m; i++) {
      printf("%d ", seq[i]);
    }
    printf("\n");
  }

  for (int i = p + 1; i <= n; i++) {
    seq[d] = i;
    print_all_seq(d + 1, i);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);

  print_all_seq(0, 0);
  return 0;
}
