#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= yellow; i++)
    {
        int x = yellow / i;
        if(yellow % i == 0)
        {
        if(brown == 2*x+ 2*i+4)
        {
            answer.push_back(x+2);
            answer.push_back(i+2);
            break;
        }
        }
    }
    return answer;
}