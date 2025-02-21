#include <string>
#include <algorithm>
using namespace std;

string solution(string a, string b) {
    string answer = "";
    int curr{};
    
    reverse(a.rbegin(), a.rend());
    reverse(b.rbegin(), b.rend());
    
    if (a.size() < b.size())
    a.resize(b.size(), '0');
    else
    b.resize(a.size(), '0');
    
    for(int i = 0; i < a.size(); i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + curr;
        curr = sum/10;
        sum %= 10;
        answer += sum+'0';
    }
    
    if(curr != 0)
        answer += to_string(curr);
    reverse(answer.begin(), answer.end());
    
    return answer;
}