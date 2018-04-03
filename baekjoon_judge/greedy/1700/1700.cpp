#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);

  int n, k;
  int schedule[101];
  set<int> pluged;

  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", schedule + i);
  }

  for (int i = 0; i < k; i++) {
    if (i < n) {
      pluged.insert(schedule[i]);
    } else {
      if (pluged.find(schedule[i]) == pluged.end()) {
        
      }
    }
  }


  return 0;
}