#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchHeights(vector<int>& inputs, vector<int>& ans, int num_person, int searchStartIdx, int sum) {
  if (sum == 100 && num_person == 7) {
    return true;
  }

  for (int idx = searchStartIdx; idx < inputs.size(); idx++) {
    if (searchHeights(inputs, ans, num_person + 1, idx + 1, sum + inputs[idx])) {
      ans.push_back(inputs[idx]);
      return true;
    }
  }

  return false;
}

int main()
{
  vector<int> inputs, ans;

  int input;
  while(scanf("%d", &input) != EOF) {
    inputs.push_back(input);
  }

  searchHeights(inputs, ans, 0, 0, 0);

  sort(ans.begin(), ans.end());
  for(auto i : ans)
    printf("%d\n", i);
  
  return 0;
}
