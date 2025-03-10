#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
	bool b{};
    string temp{};
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == ' ')
        {
            v.push_back(stoi(temp));
            temp = "";
        }
        else
            temp += s.at(i);
    }
	v.push_back(stoi(temp));
    sort(v.begin(), v.end());

    string mi = to_string(v[0]);
    string ma = to_string(v[v.size() - 1]);
    answer = mi + " " + ma;

    return answer;
}