#include <iostream>
#include <string>

int main() 
{
  std::string input;
  std::string inputs[100];

  int idx = 0;
  while(true)
  {
    getline(std::cin, input);
    if (std::cin.eof())
      break;
    inputs[idx++] = input;

  }

  for (int i = 0; i < idx; i++)
  {
    std::cout << inputs[i] << '\n';
  }

  return 0;
}
