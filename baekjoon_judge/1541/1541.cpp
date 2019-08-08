// 이 문제는 가장 작은 합을 찾아야하는 문제이다.
// 이 때 가장 작은 합을 구하기 위해서는 계산 전에 괄호를 이용해 최대한 많은 수를 음수로 만들고,
// 같은 수의 음수가 나오는 case가 2개 이상이면 음수의 합이 가장 큰 쪽으로 골라야 한다.
//
// 그런데 사실은 마이너스 기호가 나오면 괄호를 통해 뒤의 플러스 기호를 죄다 마이너스로 고칠 수 있다는 것이다.
// 숫자 앞에 마이너스 기호가 있다면 빼버리면 되고,
// 숫자 앞에 플러스 기호가 있다면 앞에 있는 기호들 중에 가장 가까운 마이너스 기호를 통해 음수로 바꿔 빼버리면 된다.
//
// 따라서 처음 마이너스 기호가 발견되면 그냥 뒤에 나오는 모든 수는 빼버리면 된다.
//
// 새로 배운 사실은 EOF가 ctrl + D 라는 것이다.
#include <iostream>
using namespace std;

int main() {
    int smallest_sum = 0;
    int tmp_value = 0;
	// 첫 번째 마이너스를 체크해야한다. 이 문제는 첫 번째 마이너스를 찾게되면 그 뒤에 나오는 수는 다 빼버려야 한다.
    bool first_minus = false;
    char c = 0;
    
	// 아래 scanf("%c", &c) == 1을 반드시 기억한다.
    while (scanf("%c", &c) == 1) {
        if ('0' <= c && c <= '9') {
            if (tmp_value == 0) {
                tmp_value += c - '0';
            } else {
                tmp_value *= 10;
                tmp_value += c - '0';
            }
        } else {
            if (first_minus) {
                smallest_sum -= tmp_value;
            } else {
                smallest_sum += tmp_value;
            }
            tmp_value = 0;
            
            if (!first_minus && c == '-') {
                first_minus = true;
            }
        }
    }
    
    printf("%d\n", smallest_sum);
    
    return 0;
}

