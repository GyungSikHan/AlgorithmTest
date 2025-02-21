#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    float temp{};
    temp = (float)num1 / (float)num2;
    temp*= 1000;
    answer = temp;
    return answer;
}