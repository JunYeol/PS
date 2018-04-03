#include <iostream>
using namespace std;

int main() {
    int n, k;
    int coins[11];
    int coin_cnt = 0;
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (coins[i] > k) {
            continue;
        } else {
            coin_cnt += k / coins[i];
            k = k % coins[i];
        }
    }
    
    printf("%d\n", coin_cnt);
    
    return 0;
}
