#include <iostream>

int main()
{
  int n;
  scanf("%d", &n);

  int ret;
  if (n < 100) {
    ret = n;
  } else {
    // The number of X (1 <= X <= 99)
    ret = 99;
    // 100 ~ 110 is useless
    for (int i = 111; i <= n; i++) {
      int num_first = i / 100;
      int num_second = i % 100 / 10;
      int num_third = i % 10;

      if ((num_first - num_second) == (num_second - num_third))
        ret += 1;
    }
  }

  printf("%d\n", ret);

  return 0;
}
