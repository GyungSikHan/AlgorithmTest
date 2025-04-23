#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> map;
    for(string s : participant)
    {
        if(map.empty() == false && map.find(s) != map.end())
            map[s]++;
        else
            map.insert({s,1});
    }

    for (string s : completion)
    {
        if(map.find(s) != map.end())
            map[s]--;
    }
    
    for(pair<string, int> i : map)
    {
        if(i.second != 0)
        {
            answer = i.first;
            break;
        }
    }
    return answer;
}