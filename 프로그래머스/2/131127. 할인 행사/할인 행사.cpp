#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> map;

    for (int i = 0; i < want.size(); i++)
        map.insert({want[i], number[i]});
    
    // for (int i = 0; i < discount.size(); i++)
    // {
    //     unordered_map<string, int> temp = map;
    //     if(i+10 > discount.size())
    //         break;
    //     for (int j = i; j < i+10; j++)
    //     {
    //         if(temp.find(discount[j]) != temp.end())
    //             temp[discount[j]]--;
    //     }
    //     int count{};
    //     for(pair<string, int> iter : temp)
    //     {
    //         if(iter.second == 0)
    //             count++;
    //     }
    //     if(count == want.size())
    //         answer++;
    // }
for (int i = 0; i < discount.size()-9; i++)
    {
        unordered_map<string,int> temp{};
        for (int j = i; j < i+10; j++)
            temp[discount[j]]++;

        if(map == temp)
            answer++;
    }    

    return answer;
}