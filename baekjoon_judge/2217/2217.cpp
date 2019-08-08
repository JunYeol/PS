#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  int ropes[100001];
  int ans;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ropes[i];

  sort(ropes, ropes + n);

  for (int i = 0; i < n; i++)
    ropes[i] = ropes[i] * (n - i);

  ans = *max_element(ropes, ropes + n);

  cout << ans << endl;

  return 0;
}