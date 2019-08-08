#include <iostream>

int main()
{
  int q; scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    int m, n; scanf("%d %d", &m, &n);
    printf("%d\n", m + n);
  }

  return 0;
}
