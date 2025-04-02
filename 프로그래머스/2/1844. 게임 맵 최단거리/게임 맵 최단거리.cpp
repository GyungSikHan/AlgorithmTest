#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};



int solution(vector<vector<int> > maps)
{
    int answer = -1;
    bool b{};
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    vector<vector<int>> visited(n+1, vector<int>(m+1,0));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == n && y == m)
            b = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            {
                if(maps[nx][ny] == 1 && visited[nx][ny] == 0) 
                {
                    q.push({nx,ny});
                    visited[nx][ny] = visited[x][y]+1;
                }
            }
        }

    }
    if(b == true)
        answer = visited[n][m];

    return answer;
}