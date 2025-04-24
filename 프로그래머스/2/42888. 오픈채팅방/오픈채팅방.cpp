#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    unordered_map<string, string> map;
    vector<pair<string, string>> temp;

    for (int i = 0; i < record.size(); i++)
    {
        auto iter = record[i].find("Enter ");
        if(iter != string::npos)
        {
            string id{}, name{};
            int index{};
            for (int j = iter+6; j < record[i].size();j++)
            {
                name+=record[i][j];
                if(name.at(index) == ' ')
                {
                    id=name.erase(index);
                    index = 0;
                    name = "";
                }
                else
                    index++;
            }
            if(map.find(id) != map.end())
                map[id] = name;
            else
                map.insert({id, name});
            
            temp.push_back({id, "Enter"});
        }
        else if((iter = record[i].find("Leave ")) != string::npos)
        {
            string id{};
            for (int j = iter+6; j < record[i].size(); j++)
                id+=record[i][j];
            if(map.find(id) != map.end())
                temp.push_back({id, "Leave"});
        }
        else if((iter = record[i].find("Change ")) != string::npos)
        {
            string id{}, name{};
            int index{};
            for (int j = iter+6; j < record[i].size();j++)
            {
                name+=record[i][j];
                if(name.at(index) == ' ')
                {
                    id=name.erase(index);
                    index = 0;
                    name = "";
                }
                else
                    index++;
            }
            if(map.find(id) != map.end())
            {
                map[id] = name;
                //temp.push_back({id,"Change"});
            }
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        string s{};
        if(temp[i].second == "Enter")
            s = map[temp[i].first] + "님이 들어왔습니다.";
        else if(temp[i].second == "Leave")
            s = map[temp[i].first] + "님이 나갔습니다.";

        answer.push_back(s);
    }
    

    return answer;
}