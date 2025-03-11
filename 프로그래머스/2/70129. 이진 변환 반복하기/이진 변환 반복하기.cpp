#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int zero{};
int Count{};

vector<int> solution(string s)
{
    vector<int> answer;

    string temp{};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            zero++;
        else
            temp += s[i];
    }

    if(s == "1")
    {
        answer.push_back(Count);
        answer.push_back(zero);
        return answer;
    }
    Count++;

    int length = temp.size();
    string i{};
    while (length > 0)
    {
        i += to_string(length%2);
        length /= 2;
    }
    reverse(i.begin(), i.end());
    answer = solution(i);

    return answer;
}