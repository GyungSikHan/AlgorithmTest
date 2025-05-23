#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
#include<sstream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size(), 0);
    vector<vector<int>> v(id_list.size());
    unordered_map<int, int> map;
    for(string s : report)
    {
        stringstream ss(s);
        string a{},b{};
        ss>>a>>b;
        int index{}, index2{};
        for (int i = 0; i < id_list.size(); i++)
        {
            if(id_list[i] == a)
                index = i;
            else if(id_list[i] == b)
            {
                index2 = i;
            }
        }
        if(find(v[index].begin(), v[index].end(), index2) == v[index].end())
        {
            map[index2] += 1;
            v[index].push_back(index2);
        }
    }

    for(pair<int, int> iter : map)
    {
        if(iter.second >= k)
        {
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < v[i].size(); j++)
                {
                    if(v[i][j] == iter.first)
                        answer[i]++;
                }  
            }
        }
    }


    return answer;
}