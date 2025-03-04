#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> temp(10, 0);

    for(int i : numbers)
        temp[i]++;

    for (int i = 0; i < temp.size(); i++)
        if (temp[i] == 0)
            answer += i;

    return answer;
}