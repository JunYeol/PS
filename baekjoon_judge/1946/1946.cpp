#include <bits/stdc++.h>

using namespace std;

using pair_int = pair<int, int>;

bool cmp(const pair_int& a, const pair_int& b) {
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);

  int tc;
  cin >> tc;

  while(tc--) {
    int n;
    vector<pair_int> score;

    cin >> n;
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      score.push_back({a, b});
    }

    sort(begin(score), end(score), cmp);

    int ans = n;
    int max = score[0].second;
    for (int i = 1; i < n; i++) {
      if (max < score[i].second) {
        ans--;
      } else if (max > score[i].second) {
        max = score[i].second;
      }
    }

    cout << ans << endl;
  }

  return 0;
}