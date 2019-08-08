#include <bits/stdc++.h>

using pi = std::pair<int, int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  pi jewel_list[300001];
  int bags[300001];
  long long ans = 0;

  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int m, v;
    std::cin >> m >> v;
    jewel_list[i].first = m;
    jewel_list[i].second = v;
  }
  for (int i = 0; i < k; i++) {
    int c;
    std::cin >> c;
    bags[i] = c;
  }

  std::sort(jewel_list, jewel_list + n);
  std::sort(bags, bags + k);

  int checked_point = 0;
  std::priority_queue<int> pq;
  for (int i = 0; i < k; i++) {
    while (checked_point < n && jewel_list[checked_point].first <= bags[i]) {
      pq.push(jewel_list[checked_point++].second);
    }

    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  std::cout << ans << '\n';
}
