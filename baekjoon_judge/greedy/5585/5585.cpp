#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  // Variables
  int paid;
  int money[6] = {500, 100, 50, 10, 5, 1};
  int money_cnt = 0;

  // Initialization
  cin >> paid; paid = 1000 - paid;

  // greedy
  for (int i = 0; i < 6; i++) {
    if (paid >= money[i]) {
      money_cnt += paid / money[i];
      paid %= money[i];
    }
  }

  cout << money_cnt << endl;

  return 0;
}
