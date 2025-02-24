#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long temp{};
    for(int i = 1;i<=n;i++)
    {
        temp+=x;
        answer.push_back(temp);
    }
    return answer;
}