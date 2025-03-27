#include <stdio.h>

int arr[7];

void print_seq(int n, int m, int d) {
  if (!m) {
    for (int i = 0; i < d; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for (int i = 1; i <= n; i++) {
    arr[d] = i;
    print_seq(n, m - 1, d + 1);
  }
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  print_seq(n, m, 0);

  return 0;
}
