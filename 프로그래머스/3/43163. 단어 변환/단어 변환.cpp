#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    bool b{};
    for(const string& s :words)
    {
        if(s == target)
        {
            b = true;
            break;
        }
    }

    if(b == false || begin == target)
        return answer;

    vector<bool> visited(words.size(), false);

    queue<pair<string,int>> q;
    q.push({begin, 0});

    while (q.empty() == false)
    {
        string s = q.front().first;
        int n = q.front().second;
        q.pop();
        if(s == target)
            return n;
        for (int i = 0; i < words.size(); i++)
        {
            if(visited[i] == true)
                continue;

            int diffCount{};
            for (int j = 0; j < s.size(); j++)
            {
                if(s.at(j) != words[i][j])
                    diffCount++;
            }

            if(diffCount == 1)
            {
                visited[i] = true;
                q.push({words[i], n+1});
            }
        }
    }

    return 0;
}