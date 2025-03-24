#include <iostream>

using namespace std;

unsigned const N = 100000;
int arr[N];
long long segment_tree[N * 4];

void build(unsigned n, unsigned start, unsigned end) {
  if (start == end) {
    segment_tree[n] = arr[start];
    return;
  }

  unsigned mid = (start + end) / 2;
  build(2 * n + 1, start, mid);
  build(2 * n + 2, mid + 1, end);
  segment_tree[n] = segment_tree[2 * n + 1] + segment_tree[2 * n + 2];
}

long long query(unsigned n, unsigned start, unsigned end, unsigned left,
                unsigned right) {
  if (right < start || left > end) {
    return 0;
  }

  if (left <= start && right >= end) {
    return segment_tree[n];
  }

  unsigned mid = (start + end) / 2;
  long long left_child = query(2 * n + 1, start, mid, left, right);
  long long right_child = query(2 * n + 2, mid + 1, end, left, right);
  return left_child + right_child;
}

/*
void update(unsigned n, unsigned start, unsigned end, unsigned i, int value) {
  if (start == end) {
    segment_tree[n] = value;
    return;
  }

  unsigned mid = (start + end) / 2;
  if (start <= i && i <= mid) {
    update(2 * n + 1, start, mid, i, value);
  } else {
    update(2 * n + 2, mid + 1, end, i, value);
  }

  segment_tree[n] = segment_tree[2 * n + 1] + segment_tree[2 * n + 2];
}
*/

void update(unsigned n, unsigned start, unsigned end, unsigned i,
            long long diff) {
  if (i < start || i > end) {
    return;
  }

  segment_tree[n] += diff;

  if (start != end) {
    unsigned mid = (start + end) / 2;
    update(2 * n + 1, start, mid, i, diff);
    update(2 * n + 2, mid + 1, end, i, diff);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  unsigned n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  build(0, 0, n - 1);

  for (int i = 0; i < q; i++) {
    int x, y, a;
    long long b;
    cin >> x >> y >> a >> b;

    if (x <= y) {
      cout << query(0, 0, n - 1, x - 1, y - 1) << '\n';
    } else {
      cout << query(0, 0, n - 1, y - 1, x - 1) << '\n';
    }

    long long diff = b - (long long)(arr[a - 1]);
    arr[a - 1] = b;
    update(0, 0, n - 1, a - 1, diff);
  }

  return 0;
}
