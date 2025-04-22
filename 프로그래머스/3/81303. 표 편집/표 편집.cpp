#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    stack<int> deleted;
    vector<int> up;
    vector<int> down;

    for(int i = 0; i < n+2; i++)
    {
        up.push_back(i-1);
        down.push_back(i+1);
    }

    k++;

    for (int i = 0; i < cmd.size(); i++)
    {
        if(cmd[i][0] == 'C')
        {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if(down[k] == n+1)
                k = up[k];
            else
                k = down[k];
        }
        else if(cmd[i][0] == 'Z')
        {
            int temp = deleted.top();
            down[up[temp]] = temp;
            up[down[temp]] = temp;
            deleted.pop();
            
        }
        else
        {
            int temp = stoi(cmd[i].substr(2));
            if(cmd[i][0] == 'U')
            {
                for(int j = 0; j < temp; j++)
                    k = up[k];
            }
            else
            {
                for(int j = 0; j < temp; j++)
                    k = down[k];
            }
        }
        /* code */
    }
    answer.append(n,'O');
    while(deleted.empty() == false)
    {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }
    return answer;
}