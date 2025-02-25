#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long temp = sqrt(n);
    if(temp*temp == n)
        answer = pow(temp+1,2);
    else
        answer = -1;
    
    return answer;
}