#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int dx[4] = {0,-1,0,1}, dy[4] {-1,0,1,0};

int n,m;
int times{};
int arr[100][100];
int visited[100][100];

void BFS(int x, int y)
{
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));

    while (q.empty() == false)
    {
        int currx = q.front().first;
        int curry = q.front().second;
        visited[currx][curry] = 1;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = currx+dx[i];
            int ny = curry +dy[i];
            if (nx < 0 || nx >= n || ny <0 || ny >=m)
                continue;
            if (visited[nx][ny] == 0)
            {
                if (arr[nx][ny] == 1)
                    visited[nx][ny] = 2;
                else
                    q.push(make_pair(nx,ny));
            }
        }
    }
}

void DFS(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y +dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny >=m)
            continue;
        if (visited[nx][ny] == 0)
        {
            if (arr[nx][ny] == 1)
                visited[nx][ny] = 2;
            else
                DFS(nx,ny);
        }
    }
}

int Count()
{
    int count{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 2)
                arr[i][j] = 0;

            if (arr[i][j] == 1)
                count++;
        }
    }

    return count;
}

int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int temp = Count();
    while (true)
    {
        int count = Count();
        if (count == 0)
            break;
        temp = count;
        memset(visited,0,sizeof(visited));
        DFS(0,0);
        times++;
    }
    cout<<times<<endl;
    cout<<temp<<endl;
}