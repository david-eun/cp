#include <algorithm>
#include <cstdio>

using namespace std;

int arr[100000];
pair<int, int> segment_tree[100000 * 4];

pair<int, int> build(int n, int start, int end) {
  if (start == end) {
    segment_tree[n].first = arr[start];
    segment_tree[n].second = arr[start];
    return segment_tree[n];
  }

  int mid = (start + end) / 2;
  pair<int, int> left_child = build(2 * n + 1, start, mid);
  pair<int, int> right_child = build(2 * n + 2, mid + 1, end);

  segment_tree[n].first = min(left_child.first, right_child.first);
  segment_tree[n].second = max(left_child.second, right_child.second);

  return segment_tree[n];
}

pair<int, int> query(int n, int start, int end, int left, int right) {
  if (start > right || end < left) {
    return {1000000001, 0};
  }

  if (left <= start && right >= end) {
    return segment_tree[n];
  }

  int mid = (start + end) / 2;
  pair<int, int> left_result = query(2 * n + 1, start, mid, left, right);
  pair<int, int> right_result = query(2 * n + 2, mid + 1, end, left, right);

  return {min(left_result.first, right_result.first),
          max(left_result.second, right_result.second)};
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  build(0, 0, n - 1);

  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    pair<int, int> result = query(0, 0, n - 1, a - 1, b - 1);
    printf("%d %d\n", result.first, result.second);
  }

  return 0;
}
