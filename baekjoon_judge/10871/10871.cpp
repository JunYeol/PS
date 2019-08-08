#include <iostream>

int main()
{
  int length, x; scanf("%d %d", &length, &x);

  for (int i = 0; i < length; i++)
  {
    int a; scanf("%d", &a);
    if (a < x)
      printf("%d ", a);
  }
  printf("\n");

  return 0;
}
