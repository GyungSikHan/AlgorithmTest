#include<iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < moves.size(); i++)
    {
        int temp = moves[i] - 1;
        for (int j = 0; j < board[temp].size(); j++)
        {
            if (board[j][temp] != 0)
            {
                if (st.empty() == false && st.top() == board[j][temp])
                {
                    st.pop();
                    answer += 2;
                }
                else
                    st.push(board[j][temp]);
                board[j][temp] = 0;
                break;
            }
        }
    }

    return answer;
}