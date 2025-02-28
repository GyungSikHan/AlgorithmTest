#include <string>
#include <vector>
#include<cmath>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int n = min(a,b);
    int m = max(a,b);
    for(int i = n; i <= m;i++ )
        answer += i;
    return answer;
}