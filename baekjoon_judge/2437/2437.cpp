#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  int grams[1001];
  int partial_sum[1001];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", grams + i);
  }

  // 추를 오름차순으로 정렬한 뒤, 임의의 연속된 두 지점 i, i + 1을 잡으면,
  // (1 ~ i번째 추들 부분합) + 1 < (i + 1번째 추) 이면 두 수 사이의 수들은 가지고 있는 추들로는 표현이 불가능하다.
  // 왜냐하면 1 ~ i의 부분합은 이미 1번째 추부터 i번째 추까지 다 한 번씩 사용해서 만들어진 것이기 때문에
  // 부분합과 i + 1번째 추의 무게사이의 값을 만들고 싶다면 반드시 1 ~ i번째 추들 중 하나를 한 번 더 사용해야 한다.
  // 단, 첫번째 추가 1보다 크다면 무게 1은 측정이 되지 않는 가장 작은 값이니 1을 출력한다.

  sort(grams, grams + n);

  if (1 < grams[0]) {
    printf("1\n");

    return 0;
  } else {
    int ans = 0;
    partial_sum[0] = grams[0];
    for (int i = 1; i < n; i++) {
      if (partial_sum[i - 1] + 1 < grams[i]) {
        ans = partial_sum[i - 1] + 1;
        break;
      }

      partial_sum[i] = partial_sum[i - 1] + grams[i];
    }

    if (ans != 0) {         // for문을 돌다가 break를 만나면 ans가 0이 아니므로 여기서 걸린다.
      printf("%d\n", ans);
    } else {                // for문을 다 돌면 ans가 0이므로 이 때는 모든 추의 총 합 + 1을 출력한다.
      ans = partial_sum[n - 1] + 1;
      printf("%d\n", ans);
    }
  }

  return 0;
}