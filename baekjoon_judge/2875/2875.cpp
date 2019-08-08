#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    int ans = 0;
    
    scanf("%d %d %d", &n, &m, &k);
    
    // 1. n + m이 k보다 크거나 같을 경우 반복문을 한 번 더 돌려 팀을 하나 더 만들어 반복문을 탈출한 뒤 정답에서 하나를 뺀다.
    while (n + m >= k) {
        n -= 2;
        m -= 1;
        
        ans++;
        
        // 2. n이나 m이 0일 때에는 반복문을 한 번 더 돌려 팀을 하나 더 만든 뒤 반복문을 탈출해 정답에서 하나를 뺀다.
        if (n < 0 || m < 0)
            break;
    }
    
    printf("%d\n", ans - 1);
    
    return 0;
}

