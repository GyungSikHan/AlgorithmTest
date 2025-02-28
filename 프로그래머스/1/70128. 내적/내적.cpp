#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int length = min(a.size(), b.size());
    for(int i = 0; i < length; i++)
    {
        answer += a[i]*b[i];
    }
    return answer;
}