#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(long long n) {
    vector<int> answer;
    if(n == 0)
    {
        answer.push_back(0);
        return answer;
    }
    while(n != 0)
    {
        answer.push_back(n%10);
        n /= 10;
    }
    //reverse(answer.begin(), answer.end());
    return answer;
}