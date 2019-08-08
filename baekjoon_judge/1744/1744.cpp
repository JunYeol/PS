#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> nums_minus, nums_plus;
    int ans = 0;
    // -1, 0 이 input으로 주어졌을 때, 둘이 곱해서 0을 만들어 더하는 게 최대이다.
    // 따라서 0의 역할은 음수가 홀수 개 일 때 둘 씩 짝짓고 남은 수 하나를 없애버리는 일을 한다.
    bool has_zero = false;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num > 1) {
            nums_plus.push_back(num);
        } else if (num < 0) {
            nums_minus.push_back(num);
        } else if (num == 1) {
            ans += num;
        } else if (num == 0) {
            has_zero = true;
        }
    }
    
    sort(nums_minus.begin(), nums_minus.end());
    sort(nums_plus.begin(), nums_plus.end());
    
    for (int i = 1; i < nums_minus.size(); i += 2) {
        ans += nums_minus[i - 1] * nums_minus[i];
    }
    if (nums_minus.size() % 2 == 1 && !has_zero) {
        ans += nums_minus[nums_minus.size() - 1];
    }
    
    for (int i = nums_plus.size() - 2; i >= 0; i -= 2) {
        ans += nums_plus[i] * nums_plus[i + 1];
    }
    if (nums_plus.size() % 2 == 1) {
        ans += nums_plus[0];
    }
    
    printf("%d\n", ans);
    
    return 0;
}

