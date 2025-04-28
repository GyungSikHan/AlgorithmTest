#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    char c{};
    string temp{};
    vector<string> v;
    int a{}, b{};

    for (int i = 0; i < s.size(); i++)
    {
        if (c == '\0')
            c = s[i];

        if (s[i] == c)
            a++;
        else
            b++;

        temp += s[i];
        if (a == b)
        {
            v.push_back(temp);
            temp = "";
            c = '\0';
        }
    }
    if(temp != "")
        v.push_back(temp);
    for (string t : v)
    {
        cout << t << endl;
    }

    answer = v.size();

    return answer;
}