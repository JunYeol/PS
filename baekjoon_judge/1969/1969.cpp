#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  string arr[1001];
  string ans = "";
  int dist = 0;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 0; i < m; i++) {
    int alpha_arr[26] = {0, };
    int max = 0;
    char max_char;

    for (int j = 0; j < n; j++) {
      alpha_arr[arr[j][i] - 'A'] += 1;

      if (alpha_arr[arr[j][i] - 'A'] > max) {
        max = alpha_arr[arr[j][i] - 'A'];
        max_char = arr[j][i];
      } else if (alpha_arr[arr[j][i] - 'A'] == max) {
        if (max_char - arr[j][i] > 0)
          max_char = arr[j][i];
      }
    }

    ans += max_char;
    dist += n - max;
  }

  cout << ans << '\n' << dist << '\n';

  return 0;
}