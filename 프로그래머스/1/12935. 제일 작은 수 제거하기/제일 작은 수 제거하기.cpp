#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }

    answer = arr;
    int temp = answer[0];
    int temp2{};
    for (int i = 1; i < answer.size(); i++)
    {
		if(temp > answer[i])
		{
            temp = answer[i];
            temp2 = i;
		}
    }

    answer.erase(answer.begin()+temp2);

    return answer;
}