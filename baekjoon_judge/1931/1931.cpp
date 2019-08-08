#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct meeting {
    int start;
    int end;
};

bool cmp(const meeting& a, const meeting& b) {
    if (a.end == b.end) {
        return a.start < b.start;
    } else {
        return a.end < b.end;
    }
}

int main() {
    int n;
    // end_pointer는 이전에 끝난 회의 시간을 가리키다가 다음 회의들 중 가장 빨리 끝나는 회의가 있으면 그 회의의 끝나는 시간을 가리키게 된다.
    // 이 때 처음 회의는 0시부터 빌릴 수 있고 이전 회의가 끝나고 바로 같은 시각에 다음 회의를 할 수 있기 때문에 0으로 초기화 한다.
    int end_pointer = 0;
    int meeting_cnt = 0;
    vector<meeting> meetings;
    
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        meetings.push_back({s, e});
    }
    
    sort(meetings.begin(), meetings.end(), cmp);
    for (int i = 0; i < meetings.size(); i++) {
        if (end_pointer <= meetings[i].start) {
            meeting_cnt++;
            end_pointer = meetings[i].end;
        }
    }
    
    printf("%d\n", meeting_cnt);
    return 0;
}

