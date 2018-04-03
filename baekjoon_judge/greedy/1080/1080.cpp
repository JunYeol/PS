#include <bits/stdc++.h>

using namespace std;

void filp(int (&arr)[51][51], int& x, int& y) {
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      arr[i][j] = 1 - arr[i][j];
    }
  }
}

bool isSame(int (&arr1)[51][51], int (&arr2)[51][51], int& n, int& m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr1[i][j] != arr2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  int arr1[51][51];
  int arr2[51][51];

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &arr1[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &arr2[i][j]);
    }
  }

  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (arr1[i][j] != arr2[i][j]) {
        filp(arr1, i, j);
        ans++;
      }
    }
  }

  if (isSame(arr1, arr2, n, m)) {
    printf("%d\n", ans);
  } else {
    printf("-1\n");
  }

  return 0;
}