#include <string>
#include <vector>
#include<set>
#include<algorithm>

using namespace std;

// vector<int> solution(vector<int> numbers)
// {
//     vector<int> answer;
//     sort(numbers.begin(), numbers.end());

//     for (int i = 0; i < numbers.size(); i++)
//     {
//         for (int j = i+1; j < numbers.size(); j++)
//         {
//             answer.push_back(numbers[i]+numbers[j]);
//         }
        
//     }
//     sort(answer.begin(), answer.end());
//     answer.erase(unique(answer.begin(), answer.end()),answer.end());

//     return answer;
// }

vector<int> solution(vector<int> numbers)
{
    set<int> temp;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            temp.insert(numbers[i]+numbers[j]);
        }
        
    }
    vector<int> answer(temp.begin(), temp.end());
   
    return answer;
}
