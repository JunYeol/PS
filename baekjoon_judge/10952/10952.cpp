#include <iostream>

int main()
{
  int m, n;
  while(scanf("%d %d", &m, &n) != EOF)
  {
    if (m == 0 && n == 0)
      break;

    printf("%d\n", m + n);
  }

  return 0;
}
