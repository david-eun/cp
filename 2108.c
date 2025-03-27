#include <stdio.h>
#include <stdlib.h>

int nums[500000];
int max_freq_num[500000];
int freq_map[4000 * 2 + 1] = {0};

int comp(void const* p_a, void const* p_b) {
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

  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    sum += nums[i];
    freq_map[nums[i] + 4000]++;
  }

  int max_freq = 0, m = 0;
  for (int i = 0; i < 4000 * 2 + 1; i++) {
    if (max_freq < freq_map[i]) {
      max_freq = freq_map[i];
      max_freq_num[m = 0] = i - 4000;
    } else if (max_freq == freq_map[i]) {
      max_freq_num[++m] = i - 4000;
    }
  }

  qsort(nums, n, sizeof(int), comp);
  qsort(max_freq_num, m + 1, sizeof(int), comp);

  double avg = (double)sum / n;
  if (avg > -0.5 && avg <= 0) {
    printf("0\n");
  } else {
    printf("%.0f\n", avg);
  }

  printf("%d\n", nums[n / 2]);
  printf("%d\n", max_freq_num[(m) ? 1 : 0]);
  printf("%d\n", nums[n - 1] - nums[0]);

  return 0;
}
