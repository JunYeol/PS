#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::string a, b;
  std::cin >> a >> b;
  
  std::transform(a.begin(), a.end(), a.begin(), ::tolower);
  std::transform(b.begin(), b.end(), b.begin(), ::tolower);
  
  int cmp = a.compare(b);
  if (cmp < 0)
    printf("-1\n");
  else if (cmp == 0)
    printf("0\n");
  else
    printf("1\n");
  
  return 0;
}
