#include <iostream>
#include <algorithm>

using namespace std;

int searchHighestProfit(int *t, int *p, int n, int day) {
  if (day == n)
    return 0;

  int ret = 0;
  for (int i = day; i < n; i++) {
    if (i + t[i] > n)
      continue;

    int pf = searchHighestProfit(t, p, n, i + t[i]) + p[i];

    ret = max(ret, pf);
  }
  
  return ret;
}

int main()
{
  int n;
  int t[15];
  int p[15];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ti, pi;
    scanf("%d %d", &ti, &pi);
    t[i] = ti;
    p[i] = pi;
  }

  int ans = searchHighestProfit(t, p, n, 0);
  printf("%d\n", ans);

  return 0;
}
