#include <string>
#include <vector>
#include <queue>
using namespace std;

#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q, q2, g;
    for(string s : cards1)
        q.push(s);
    for(string s : cards2)
        q2.push(s);
    for(string s : goal)
        g.push(s);

    while(g.empty() == false)
    {
        if(q.front() == g.front())
        {
            q.pop();
            g.pop();
        }
        else if(q2.front() == g.front())
        {
            q2.pop();
            g.pop();
        }
        else
            break;
    }

    if(g.empty() == false)
        answer = "No";
    else
        answer = "Yes";
    return answer;
}