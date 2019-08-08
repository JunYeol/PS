#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int p[1001];
    int p_sum = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        p_sum += p[i] * (n - i);
    }
    
    printf("%d\n", p_sum);
    
    return 0;
}

