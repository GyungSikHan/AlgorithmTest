#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    if (a - '0' > b - '0')
        return true;
    return false;
}

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), compare);
    answer = s;
    return answer;
}