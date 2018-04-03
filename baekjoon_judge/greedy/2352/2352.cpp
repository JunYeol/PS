#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  int connections[40001];
  vector<int> lis;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> connections[i];
  }

  for (int i = 0; i < n; i++) {
    if (lis.empty()) {
      lis.push_back(connections[i]);
    } else if (lis.back() < connections[i]) {
      lis.push_back(connections[i]);
    } else {
      auto it = lower_bound(begin(lis), end(lis), connections[i]);
      *it = connections[i];
    }
  }

  cout << lis.size() << endl;

  return 0;
}