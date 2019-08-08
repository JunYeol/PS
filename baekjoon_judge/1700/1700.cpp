#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, k;
  int schedule[101];
  int plug[101];
  int ans = 0;

  cin >> n >> k;
  for (int i = 0; i < k; i++)
    cin >> schedule[i];
  memset(plug, 0, sizeof(int) * k);

  for (int i = 0; i < k; i++) {
    // 멀티탭에 안쓰는 플러그가 있는지, 그리고 현재 전기용품이 꽂혀있는지 체크한다.
    bool isPluged = false;
    bool isEmpty = false;
    for (int j = 0; j < n; j++) {
      if (plug[j] == schedule[i]) {
        isPluged = true;
      } else if (plug[j] == 0) {
        isEmpty = true;
      }
    }

    if (isEmpty) {
      if (!isPluged) {
        // 만약 현재의 전기용품이 꽂혀있지 않고 안쓰는 플러그가 있다면,
        // 비어있는 플러그를 찾아 꽂는다.
        for (int j = 0; j < n; j++) {
          if (plug[j] == 0) {
            plug[j] = schedule[i];
            break;
          }
        }
      }
      // 비어있는 플러그가 있지만 현재 전기용품이 이미 꽂혀있으면 패스한다.
    } else {
      if (!isPluged) {
        // 비어있는 플러그가 없고, 현재 전기용품을 꽂아야 한다면,
        // 현재 꽂혀있는 전기용품들 중에 다음에 쓰이는 순서가 가장 늦거나 아예 안쓰이게 되는 전기용품을 빼낸다.

        // 일단 빼내야 하는 전기용품을 찾는다.
        int longest_next_idx = -1;
        int longest_period = -12345;
        for (int j = 0; j < n; j++) {
          bool no_next = true;          // 만약 이후에 안쓰이는 전기용품이 꽂혀있을 경우를 나타내는 변수이다.
          for (int m = i + 1; m < k; m++) {
            if (schedule[m] == plug[j]) {
              if (longest_period < m) {
                longest_period = m;
                longest_next_idx = j;
              }
              no_next = false;
              break;                    // 다음에 쓰이는지 확인하는 거니까 한 번 확인하면 그 다음 것은 체크할 이유가 없다.
            }
          }
          // 안쓰이는 전기용품이면 걔를 바꿔야 한다.
          if (no_next) {
            longest_period = 12345;
            longest_next_idx = j;
            break;
          }
        }

        plug[longest_next_idx] = schedule[i];
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}