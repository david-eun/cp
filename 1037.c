#include <stdio.h>
#include <stdlib.h>

int factors[50];

int comp(const void* p_a, const void* p_b) {
  int a = *(int*)p_a;
  int b = *(int*)p_b;

  if (a > b) {
    return 1;
  } else if (a < b) {
    return -1;
  } else {
    return 0;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &factors[i]);
  }

  qsort(factors, n, sizeof(int), comp);

  if (n % 2) {
    printf("%d", factors[n / 2] * factors[n / 2]);
  } else {
    printf("%d", factors[n / 2 - 1] * factors[n / 2]);
  }

  printf("\n");
  return 0;
}
