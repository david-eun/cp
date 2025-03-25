#include <algorithm>
#include <iostream>

using namespace std;

typedef struct Element {
  int i, v;
} Element;

bool element_compare(Element a, Element b) {
  if (a.v == b.v) {
    return a.i < b.i;
  }

  return a.v < b.v;
}

int const N = 500000;
Element arr[N];
int segment_tree[N * 4] = {0};

void insert(int n, int start, int end, int i) {
  if (i < start || i > end) {
    return;
  }

  segment_tree[n]++;

  if (start != end) {
    int mid = (start + end) / 2;
    insert(2 * n + 1, start, mid, i);
    insert(2 * n + 2, mid + 1, end, i);
  }
}

long long query(int n, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  }

  if (left <= start && right >= end) {
    return segment_tree[n];
  }

  int mid = (start + end) / 2;
  long long left_result = query(2 * n + 1, start, mid, left, right);
  long long right_result = query(2 * n + 2, mid + 1, end, left, right);
  return left_result + right_result;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].v;
    arr[i].i = i;
  }

  sort(arr, arr + n, element_compare);

  long long num_swaps = 0;
  for (int i = 0; i < n; i++) {
    num_swaps += query(0, 0, n - 1, arr[i].i, n - 1);
    insert(0, 0, n - 1, arr[i].i);
  }

  cout << num_swaps << '\n';
}
