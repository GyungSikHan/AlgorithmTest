#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<float, int> a, pair<float, int> b) {
    if (a.first == b.first) 
        return a.second < b.second;  // 실패율 같으면 스테이지 번호 오름차순
    return a.first > b.first;        // 실패율 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> temp(N + 2, 0);  // 스테이지 1~N+1 저장용

    for (int stage : stages) 
        if (stage <= N) temp[stage]++;

    vector<pair<float, int>> temp2;
    int total = stages.size();

    for (int i = 1; i <= N; i++) {
        float rate = (total == 0) ? 0 : (float)temp[i] / total;
        temp2.push_back({rate, i});
        total -= temp[i];
    }

    sort(temp2.begin(), temp2.end(), compare);

    for (auto& p : temp2) 
        answer.push_back(p.second);

    return answer;
}
