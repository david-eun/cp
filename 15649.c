#include <stdbool.h>
#include <stdio.h>

int n, m;
int seq[8];
bool num_in_seq[8] = {0};

void print_all_seq(int k) {
  if (!k) {
    for (int i = 0; i < m; i++) {
      printf("%d ", seq[i]);
    }
    printf("\n");
  }

  for (int i = 1; i <= n; i++) {
    if (num_in_seq[i]) {
      continue;
    }

    num_in_seq[i] = true;
    seq[m - k] = i;
    print_all_seq(k - 1);
    num_in_seq[i] = false;
  }
}

int main(void) {
  scanf("%d %d", &n, &m);

  print_all_seq(m);
  return 0;
}
